#include <QtTest>
#include "../squareobject.h"

class test1 : public QObject {
    Q_OBJECT

private slots:

    void testBorderColor() {
         // Test case for borderColor and setBorderColor functions
        SquareObject obj;

        // Initially, borderColor should be empty
        QCOMPARE(obj.borderColor(), QString());

        // Test setting and getting borderColor
        const QString newColor = "#FF0000";
        obj.setBorderColor(newColor);
        QCOMPARE(obj.borderColor(), newColor);
    }

    // Test case for coolerCurrent and setCoolerCurrent functions
    void testCoolerCurrent() {
        SquareObject obj;

        // Initially, coolerCurrent should be 0.0
        QCOMPARE(obj.coolerCurrent(), 0.0);

        // Test setting and getting coolerCurrent
        const double newCurrent = 25.0;
        obj.setCoolerCurrent(newCurrent);
        QCOMPARE(obj.coolerCurrent(), newCurrent);

        // Test that emitting signal works
        QSignalSpy spy(&obj, SIGNAL(coolerCurrentChanged()));
        obj.setCoolerCurrent(newCurrent);
        QCOMPARE(spy.count(), 0); // No signal emitted since value didn't change

        obj.setCoolerCurrent(30.0);
        QCOMPARE(spy.count(), 1); // Signal emitted after value changed
    }

    // Test case for coolerVoltage and setCoolerVoltage functions
    void testCoolerVoltage() {
        SquareObject obj;

        // Initially, coolerVoltage should be 0.0
        QCOMPARE(obj.coolerVoltage(), 0.0);

        // Test setting and getting coolerVoltage
        const double newVoltage = 12.5;
        obj.setCoolerVoltage(newVoltage);
        QCOMPARE(obj.coolerVoltage(), newVoltage);

        // Test that emitting signal works
        QSignalSpy spy(&obj, SIGNAL(coolerVoltageChanged()));
        obj.setCoolerVoltage(newVoltage);
        QCOMPARE(spy.count(), 0); // No signal emitted since value didn't change

        obj.setCoolerVoltage(15.0);
        QCOMPARE(spy.count(), 1); // Signal emitted after value changed
    }
};

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
