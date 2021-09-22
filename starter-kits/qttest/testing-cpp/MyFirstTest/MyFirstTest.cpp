// Copyright (C) 2021, XXX

#include <QtTest>

// Add your project-specific #include's here.

class MyFirstTest : public QObject
{
    Q_OBJECT

private slots:
    /*
     * Called before the first test function is executed.
     * void initTestCase();
     *
     * Called before each test function is executed.
     * void init();
     *
     * Called after every test function.
     * void cleanup();
     *
     * Called after the last test function was executed
     * void cleanupTestCase();
     */

    void test1();

};

void MyFirstTest::test1()
{
    QFAIL("Your test is running! Now delete this line and watch your test pass.");
    /*
     * Instantiate the class or call the function you want to test.
     * Then delete this comment.
     */
}

QTEST_GUILESS_MAIN(MyFirstTest)

#include "MyFirstTest.moc"
