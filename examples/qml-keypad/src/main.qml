// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("TDD on QML Keypad")

    Keypad
    {
        anchors.fill: parent
    }
}
