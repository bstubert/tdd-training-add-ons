// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Window

import EmUse.Controls

Window
{
    width: 200
    height: 240
    visible: true
    title: qsTr("TDD on QML Keypad")

    property string acceptedValue: "77"

    Keypad
    {
        anchors.fill: parent
        value: acceptedValue
        onAccepted:
        {
            acceptedValue = value
            reset("Accepted")
        }
        onRejected:
        {
            value = acceptedValue
            reset("Rejected")
        }

        function reset(result)
        {
            console.log(result, " value: ", value)
            wasDigitEntered = false
        }
    }
}
