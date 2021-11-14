// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtTest

TestCase
{
    name: "EnterIntegerNumber"

    Keypad
    {
        id: keypad
    }

    function test_setup()
    {
        verify(false, "All set up! Now write a proper test");
    }
}
