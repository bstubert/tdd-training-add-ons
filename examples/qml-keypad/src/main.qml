// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick 2.15
import QtQuick.Window 2.15

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
