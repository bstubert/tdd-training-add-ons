// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Pane
{
    property int value: 0

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
            onClicked: value = 1
        }
    }
}
