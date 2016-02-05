// Copyright (c) 2011-2014 The Aricoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ARICOINADDRESSVALIDATOR_H
#define ARICOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AricoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AricoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Aricoin address widget validator, checks for a valid aricoin address.
 */
class AricoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AricoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // ARICOINADDRESSVALIDATOR_H
