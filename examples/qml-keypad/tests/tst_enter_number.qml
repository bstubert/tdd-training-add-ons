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

    function test_enterFirstDigit()
    {
        verify(false, "All set up! Now write a proper test");
    }
}
