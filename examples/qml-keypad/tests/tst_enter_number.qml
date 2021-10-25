// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtTest 1.15
import QtQuick.Window 2.15

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

    function test_enter1()
    {
        var key1 = findChild(keypad, "key1")
        mouseClick(key1)
        compare(keypad.value, 1)
    }
}
