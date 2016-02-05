#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?req-dontexist="));
    QVERIFY(!GUIUtil::parseAricoinURI(uri, &rv));

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?dontexist="));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?amount=0.001"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?amount=1.001"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseAricoinURI("aricoin://5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseAricoinURI(uri, &rv));

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseAricoinURI(uri, &rv));

    uri.setUrl(QString("aricoin:5St1TKAdbbBWrsxrUfcrtcXX52UrVVvCv8?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseAricoinURI(uri, &rv));
}
