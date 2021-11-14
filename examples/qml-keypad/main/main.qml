// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Window

import EmUse.Controls

Window {
    width: 400
    height: 300
    visible: true
    title: qsTr("TDD on QML Keypad")

    Keypad
    {
        anchors.fill: parent
    }
}
