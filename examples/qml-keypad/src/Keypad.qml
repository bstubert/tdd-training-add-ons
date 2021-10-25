// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Pane
{
    property int value: parseInt(valueDisplay.text)

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
            id: button1
            text: "1"
        }
    }
}
