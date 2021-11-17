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

    function init()
    {
        keypad.value = ""
        compare(keypad.value, "")
        var valueDisplay = findChild(keypad, "valueDisplay")
        compare(valueDisplay.text, "")
    }

    function test_pressKey1OneTime()
    {
        var key1 = findChild(keypad, "key1")
        var valueDisplay = findChild(keypad, "valueDisplay")

        mouseClick(key1)
        compare(keypad.value, "1")
        compare(valueDisplay.text, "1")
    }

    function test_pressKey1TwoTimes()
    {
        var key1 = findChild(keypad, "key1")
        var valueDisplay = findChild(keypad, "valueDisplay")

        mouseClick(key1)
        compare(keypad.value, "1")
        compare(valueDisplay.text, "1")

        mouseClick(key1)
        compare(keypad.value, "11")
        compare(valueDisplay.text, "11")
    }
}
