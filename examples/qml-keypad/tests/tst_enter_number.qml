// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtTest 1.15

TestCase
{
    name: "EnterIntegerNumber"

    KeypadFixture
    {
        id: keypad
    }

    function test_enter1()
    {
//        mouseClick(keypad.button1)
        compare(keypad.value, 1)
    }
}
