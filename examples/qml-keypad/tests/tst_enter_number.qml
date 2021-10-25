// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtTest 1.15

TestCase
{
    name: "EnterIntegerNumber"

    Keypad
    {
        id: keypad
    }

    function test_enter1()
    {
        // User clicks button "1"
        compare(keypad.value, 1)
    }
}
