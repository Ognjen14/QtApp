import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import TcpServer 1.0

Window {
    id: root
    visible: true
    width: 1920
    height: 1080
    minimumHeight: 1000
    minimumWidth: 900

    // SquareFuild component centered within the parent Window
    SquareFuild {
        anchors.centerIn: parent
    }
}


