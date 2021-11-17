// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane
{
    property string value: ""

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
                onClicked: value += "1"
            }

            Button
            {
                objectName: "key2"
                text: "2"
                onClicked: value += "2"
            }

            Button
            {
                objectName: "key3"
                text: "3"
                onClicked: value += "3"
            }

            Button
            {
                objectName: "key4"
                text: "4"
                onClicked: value += "4"
            }

            Button
            {
                objectName: "key5"
                text: "5"
                onClicked: value += "5"
            }

            Button
            {
                objectName: "key6"
                text: "6"
                onClicked: value += "6"
            }

            Button
            {
                objectName: "key7"
                text: "7"
                onClicked: value += "7"
            }

            Button
            {
                objectName: "key8"
                text: "8"
                onClicked: value += "8"
            }

            Button
            {
                objectName: "key9"
                text: "9"
                onClicked: value += "9"
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
                onClicked: value += "0"
            }

            Button
            {
                objectName: "keyClear"
                text: "C"
                enabled: false
            }
        }
    }
}
