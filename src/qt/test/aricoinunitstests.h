#ifndef ARICOINUNITSTESTS_H
#define ARICOINUNITSTESTS_H

#include <QObject>
#include <QTest>

class AricoinUnitsTests : public QObject
{
    Q_OBJECT

private slots:
    void formatTests();
    void parseTests();
};

#endif // ARICOINUNITSTESTS_H
