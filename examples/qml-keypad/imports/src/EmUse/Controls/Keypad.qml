// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane
{
    signal accepted()
    signal rejected()

    property string value: ""
    property bool wasDigitEntered: false

    function addDigit(digit)
    {
        if (!wasDigitEntered)
        {
            wasDigitEntered = true
            value = digit
        }
        else
        {
            value += digit
        }
    }

    ColumnLayout
    {
        anchors.fill: parent

        TextField
        {
            id: valueDisplay
            objectName: "valueDisplay"
            readOnly: true
            text: value
            horizontalAlignment: Text.AlignRight
        }

        GridLayout
        {
            columns: 3

            Button
            {
                objectName: "key1"
                text: "1"
                onClicked: addDigit("1")
            }

            Button
            {
                objectName: "key2"
                text: "2"
                onClicked: addDigit("2")
            }

            Button
            {
                objectName: "key3"
                text: "3"
                onClicked: addDigit("3")
            }

            Button
            {
                objectName: "key4"
                text: "4"
                onClicked: addDigit("4")
            }

            Button
            {
                objectName: "key5"
                text: "5"
                onClicked: addDigit("5")
            }

            Button
            {
                objectName: "key6"
                text: "6"
                onClicked: addDigit("6")
            }

            Button
            {
                objectName: "key7"
                text: "7"
                onClicked: addDigit("7")
            }

            Button
            {
                objectName: "key8"
                text: "8"
                onClicked: addDigit("8")
            }

            Button
            {
                objectName: "key9"
                text: "9"
                onClicked: addDigit("9")
            }

            Button
            {
                objectName: "keyPlusMinus"
                text: "\u00b1"
                enabled: false
            }

            Button
            {
                objectName: "key0"
                text: "0"
                onClicked: addDigit("0")
            }

            Button
            {
                objectName: "keyClear"
                text: "C"
                enabled: false
            }
        }

        RowLayout
        {
            Button
            {
                objectName: "cancel"
                text: "Cancel"
                onClicked: rejected()
            }

            Button
            {
                objectName: "ok"
                text: "OK"
                onClicked: accepted()
            }
        }
    }
}
