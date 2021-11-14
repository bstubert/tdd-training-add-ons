// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtTest
import QtQuick.Window

TestCase
{
    name: "EnterIntegerNumber"
    when: windowShown

    Window
    {
        width: 640
        height: 480
        visible: true

        Keypad
        {
            id: keypad
            anchors.fill: parent
        }
    }

    function test_setup()
    {
        verify(false, "All set up! Now write a proper test");
    }
}
