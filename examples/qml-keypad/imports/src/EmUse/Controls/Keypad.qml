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
            text: "933"
            horizontalAlignment: Text.AlignRight
        }
    }
}
