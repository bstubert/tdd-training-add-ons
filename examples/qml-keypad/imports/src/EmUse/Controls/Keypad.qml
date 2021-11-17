// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane
{
    property real value: 0.0

    ColumnLayout
    {
        anchors.fill: parent

        TextField
        {
            id: valueDisplay
            objectName: "valueDisplay"
            readOnly: true
            text: value.toFixed(0)
            horizontalAlignment: Text.AlignRight
        }

        Button
        {
            id: key1
            objectName: "key1"
            text: "1"
            onClicked: value = 1.0
        }
    }
}
