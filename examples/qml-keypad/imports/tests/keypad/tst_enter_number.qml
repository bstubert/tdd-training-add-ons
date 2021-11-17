// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtTest

TestCase
{
    name: "EnterIntegerNumber"
    when: windowShown

    Window
    {
        width: 400
        height: 300
        visible: true

        Keypad
        {
            id: keypad
            anchors.fill: parent
        }
    }

    function test_pressKey1()
    {
        var key1 = findChild(keypad, "key1")
        mouseClick(key1)
        compare(keypad.value, "1")

        var valueDisplay = findChild(keypad, "valueDisplay")
        compare(valueDisplay.text, "1")
    }
}
