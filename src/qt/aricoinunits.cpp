// Copyright (c) 2011-2013 The Aricoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "aricoinunits.h"

#include <QStringList>
#include <QLocale>

AricoinUnits::AricoinUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<AricoinUnits::Unit> AricoinUnits::availableUnits()
{
    QList<AricoinUnits::Unit> unitlist;
    unitlist.append(MARI);
    unitlist.append(kARI);
    unitlist.append(ARI);
//    unitlist.append(Koinu);
    return unitlist;
}

bool AricoinUnits::valid(int unit)
{
    switch(unit)
    {
    case MARI:
    case kARI:
    case ARI:
    case Koinu:
        return true;
    default:
        return false;
    }
}

QString AricoinUnits::name(int unit)
{
    switch(unit)
    {
    case MARI: return QString("MARI");
    case kARI: return QString("kARI");
    case ARI: return QString("ARI");
    case Koinu: return QString("Koinu");
    default: return QString("???");
    }
}

QString AricoinUnits::description(int unit)
{
    switch(unit)
    {
    case MARI: return QString("Mega-Aricoin (1,000,000 ARI)");
    case kARI: return QString("Kilo-Aricoin (1000 ARI)");
    case ARI: return QString("Aricoin");
    case Koinu: return QString("Koinu (1 / 100,000,000");
    default: return QString("???");
    }
}

qint64 AricoinUnits::factor(int unit)
{
    switch(unit)
    {
    case MARI: return Q_INT64_C(100000000000000);
    case kARI: return Q_INT64_C(100000000000);
    case ARI:  return Q_INT64_C(100000000);
    case Koinu: return Q_INT64_C(1);
    default:    return Q_INT64_C(100000000);
    }
}

qint64 AricoinUnits::maxAmount(int unit)
{
    switch(unit)
    {
    case MARI: return Q_INT64_C(900000);
    case kARI: return Q_INT64_C(900000000);
    case ARI:  return Q_INT64_C(900000000000);    //less than the coin supply until the year 2170
    case Koinu: return Q_INT64_C(9000000000000000000); // Slightly under max value for int64
    default:   return 0;
    }
}

int AricoinUnits::amountDigits(int unit)
{
    switch(unit)
    {
    case MARI: return 6;  // 900,000 (# digits, without commas)
    case kARI: return 9;  // 900,000,000
    case ARI:  return 12; // 900,000,000,000
    case Koinu: return 19; // 9,000,000,000,000,000,000
    default: return 0;
    }
}

int AricoinUnits::decimals(int unit)
{
    switch(unit)
    {
    case MARI: return 14;
    case kARI: return 11;
    case ARI: return 8;
    case Koinu: return 0;
    default: return 0;
    }
}

QString AricoinUnits::format(int unit, qint64 n, bool fPlus, bool fTrim, const QLocale &locale_in)
{
    // Note: not using straight sprintf here because we do NOT want
    // localized number formatting.
    if(!valid(unit))
        return QString(); // Refuse to format invalid unit
    QLocale locale(locale_in);
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);

    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    qint64 remainder = n_abs % coin;
    // Quotient has group (decimal) separators if locale has this enabled
    QString quotient_str = locale.toString(quotient);
    // Remainder does not have group separators
    locale.setNumberOptions(QLocale::OmitGroupSeparator | QLocale::RejectGroupSeparator);
    QString remainder_str = locale.toString(remainder).rightJustified(num_decimals, '0');

    if(fTrim)
    {
        // Right-trim excess zeros after the decimal point
        int nTrim = 0;
        for (int i = remainder_str.size()-1; i>=2 && (remainder_str.at(i) == '0'); --i)
            ++nTrim;
        remainder_str.chop(nTrim);
    }

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n >= 0)
        quotient_str.insert(0, '+');
    return quotient_str + locale.decimalPoint() + remainder_str;
}

QString AricoinUnits::formatWithUnit(int unit, qint64 amount, bool plussign, bool trim, const QLocale &locale)
{
    return format(unit, amount, plussign, trim) + QString(" ") + name(unit);
}
bool AricoinUnits::parse(int unit, const QString &value, qint64 *val_out, const QLocale &locale_in)
{
    if(!valid(unit) || value.isEmpty())
        return false; // Refuse to parse invalid unit or empty string

    QLocale locale(locale_in);
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    QStringList parts = value.split(locale.decimalPoint());
    bool ok = false;

    if(parts.size() > 2)
        return false; // More than one decimal point

    // Parse whole part (may include locale-specific group separators)
#if QT_VERSION < 0x050000
    qint64 whole = locale.toLongLong(parts[0], &ok, 10);
#else
    qint64 whole = locale.toLongLong(parts[0], &ok);
#endif
    if(!ok)
        return false; // Parse error
    if(whole > maxAmount(unit) || whole < 0)
        return false; // Overflow or underflow

    // Parse decimals part (if present, may not include group separators)
    qint64 decimals = 0;
    if(parts.size() > 1)
    {
        if(parts[1].size() > num_decimals)
            return false; // Exceeds max precision
        locale.setNumberOptions(QLocale::OmitGroupSeparator | QLocale::RejectGroupSeparator);
#if QT_VERSION < 0x050000
        decimals = locale.toLongLong(parts[1].leftJustified(num_decimals, '0'), &ok, 10);
#else
        decimals = locale.toLongLong(parts[1].leftJustified(num_decimals, '0'), &ok);
#endif
        if(!ok || decimals < 0)
            return false; // Parse error
    }

    if(val_out)
    {
        *val_out = whole * coin + decimals;
    }
    return ok;
}

int AricoinUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant AricoinUnits::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant(static_cast<int>(unit));
        }
    }
    return QVariant();
}
