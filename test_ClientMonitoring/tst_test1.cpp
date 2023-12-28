#include <QtTest>
/* This is test of test */
class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
};

test1::test1(){ }

test1::~test1(){ }

void test1::test_case1()
{
    QVERIFY2(2 + 2 == 4, "Incorrect addition result!");
}

void test1::test_case2()
{

    QString str = "Hello";
    QVERIFY2(!str.isEmpty(), "String should not be empty!");
}

void test1::test_case3()
{
    QVector<int> vec;
    QCOMPARE(vec.size(), 0);
}

void test1::test_case4()
{
    // Failing test case on purpose
    QVERIFY2(5 * 5 == 30, "Incorrect multiplication result!");
}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
