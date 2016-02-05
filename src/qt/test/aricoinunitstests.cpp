#include "aricoinunitstests.h"

#include "aricoinunits.h"

#include <QUrl>

void AricoinUnitsTests::parseTests()
{
    qint64 value = 0;

    /// Tests with en_US locale
    QLocale locale1("en_US");
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "0", &value, locale1));
    QCOMPARE(value, 0LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1", &value, locale1));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1.0", &value, locale1));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "10.0", &value, locale1));
    QCOMPARE(value, 1000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1,000.0", &value, locale1));
    QCOMPARE(value, 100000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1,000,000.0", &value, locale1));
    QCOMPARE(value, 100000000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::Koinu, "1,000,000,000", &value, locale1));
    QCOMPARE(value, 1000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::kARI, "1.0", &value, locale1));
    QCOMPARE(value, 100000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::MARI, "1.0", &value, locale1));
    QCOMPARE(value, 100000000000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::kARI, "0.001", &value, locale1));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::MARI, "0.000001", &value, locale1));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "0.00000001", &value, locale1));
    QCOMPARE(value, 1LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::kARI, "0.00000000001", &value, locale1));
    QCOMPARE(value, 1LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::MARI, "0.00000000000001", &value, locale1));
    QCOMPARE(value, 1LL);
    //Without seperator
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1000.0", &value, locale1));
    QCOMPARE(value, 100000000000LL);
    //MAX_MONEY
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "10000000000", &value, locale1));
    QCOMPARE(value, 1000000000000000000LL);
    // Fail: group separator in wrong place
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0,00", &value, locale1));
    // Fail: group separator in decimals
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0.0,000", &value, locale1));
    // Fail: multiple decimal separators
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0.000.000", &value, locale1));

    /// Tests with nl_NL locale
    QLocale locale2("nl_NL");
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1", &value, locale2));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1,0", &value, locale2));
    QCOMPARE(value, 100000000LL);
    QVERIFY(AricoinUnits::parse(AricoinUnits::Koinu, "1.000.000", &value, locale2));
    QCOMPARE(value, 1000000LL);
    // Fail: multiple decimal separators
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0,000,000", &value, locale2));

    /// Tests with de_CH locale
    QLocale locale3("de_CH");
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "123'456.78", &value, locale3));
    QCOMPARE(value, 12345678000000LL);
    // Fail: multiple decimal separators
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0.000.000", &value, locale3));

    /// Tests with c locale
    QLocale locale4(QLocale::c());
    locale4.setNumberOptions(QLocale::OmitGroupSeparator | QLocale::RejectGroupSeparator);
    QVERIFY(AricoinUnits::parse(AricoinUnits::ARI, "1000.00000000", &value, locale4));
    QCOMPARE(value, 100000000000LL);
    // Fail: group separator
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "1,000.00", &value, locale4));
    // Fail: too many decimals
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "1000.000000000", &value, locale4));
    QVERIFY(!AricoinUnits::parse(AricoinUnits::Koinu, "1.0", &value, locale4));
    //no overflow because Aricoin has unlimited money supply
    /*// Fail: overflow
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "10000000000.1", &value, locale4));
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "92233720368547758090.0", &value, locale4));*/
    // Fail: underflow
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "-1000000.0", &value, locale4));
    // Fail: sign in decimals
    QVERIFY(!AricoinUnits::parse(AricoinUnits::ARI, "0.-1000000", &value, locale4));
}

void AricoinUnitsTests::formatTests()
{
    /// Tests with en_US locale
    QLocale locale1("en_US");
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 0, false, false, locale1), QString("0.00000000"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 0, false, true, locale1), QString("0.00"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::kARI, 0, false, false, locale1), QString("0.00000000000"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::MARI, 0, false, false, locale1), QString("0.00000000000000"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::Koinu, 0, false, false, locale1), QString("0.0"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 0, true, false, locale1), QString("+0.00000000"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::Koinu, 100000000, false, true, locale1), QString("100,000,000.0"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::Koinu, 100000000, true, true, locale1), QString("+100,000,000.0"));

    QCOMPARE(AricoinUnits::formatWithUnit(AricoinUnits::ARI, 100000000000000LL, false, true, locale1), QString("1,000,000.00 ARI"));
    QCOMPARE(AricoinUnits::formatWithUnit(AricoinUnits::kARI, 100000000000000LL, false, true, locale1), QString("1,000.00 kARI"));
    QCOMPARE(AricoinUnits::formatWithUnit(AricoinUnits::MARI, 100000000000000LL, false, true, locale1), QString("1.00 MARI"));

    /// Tests with nl_NL locale
    QLocale locale2("nl_NL");
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 100000000000000LL, false, true, locale2), QString("1.000.000,00"));

    /// Tests with de_CH locale
    QLocale locale3("de_CH");
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 100000000000000LL, false, true, locale3), QString("1'000'000.00"));

    /// Tests with c locale (with and without group separators)
    QLocale locale4(QLocale::c());
    locale4.setNumberOptions(QLocale::OmitGroupSeparator | QLocale::RejectGroupSeparator);
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 100000000000000LL, false, true, QLocale::c()), QString("1,000,000.00"));
    QCOMPARE(AricoinUnits::format(AricoinUnits::ARI, 100000000000000LL, false, true, locale4), QString("1000000.00"));
}

