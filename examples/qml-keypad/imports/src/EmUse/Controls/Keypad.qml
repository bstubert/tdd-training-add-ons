// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane
{
    ColumnLayout
    {
        anchors.fill: parent

        TextField
        {
            id: valueDisplay
            readOnly: true
            text: ""
            horizontalAlignment: Text.AlignRight
        }

        Button
        {
            id: key1
            objectName: "key1"
            text: "1"
        }
    }
}