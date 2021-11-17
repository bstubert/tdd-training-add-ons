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

    property QtObject valueDisplay: findChild(keypad, "valueDisplay")
    property QtObject key1: findChild(keypad, "key1")
    property QtObject key2: findChild(keypad, "key2")
    property QtObject key3: findChild(keypad, "key3")
    property QtObject key4: findChild(keypad, "key4")
    property QtObject key5: findChild(keypad, "key5")
    property QtObject key6: findChild(keypad, "key6")
    property QtObject key7: findChild(keypad, "key7")
    property QtObject key8: findChild(keypad, "key8")
    property QtObject key9: findChild(keypad, "key9")
    property QtObject key0: findChild(keypad, "key0")

    function init()
    {
        keypad.value = ""
        compare(keypad.value, "")
        compare(valueDisplay.text, "")
    }

    function test_enterNumber12007()
    {
        mouseClick(key1)
        mouseClick(key2)
        mouseClick(key0)
        mouseClick(key0)
        mouseClick(key7)
        compare(keypad.value, "12007")
        compare(valueDisplay.text, "12007")
    }

    function test_enterNumber38398()
    {
        mouseClick(key3)
        mouseClick(key8)
        mouseClick(key3)
        mouseClick(key9)
        mouseClick(key8)
        compare(keypad.value, "38398")
        compare(valueDisplay.text, "38398")
    }

    function test_enterNumber43566()
    {
        mouseClick(key4)
        mouseClick(key3)
        mouseClick(key5)
        mouseClick(key6)
        mouseClick(key6)
        compare(keypad.value, "43566")
        compare(valueDisplay.text, "43566")
    }
}
