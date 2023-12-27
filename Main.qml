import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import TcpServer 1.0
Window {
    id:root
    visible: true
    width: 1920
    height: 1080
    minimumHeight: 1000
    minimumWidth: 1000

    GridLayout {
        id: grid
        rows: 5
        columns: 4
        columnSpacing: 20
        rowSpacing: 20
        anchors.centerIn: parent
        Repeater {
            model: gridModel // Here we can control number of SquareObjects(Fuilds) inside matrix!
            SquareFuild{
                id:root2
                width: 1920 / 10
                height: 1080 / 10 * 1.7
                indexNumber: index + 1
                idNumber: index + 1555
            }
        }
    }
    onWidthChanged: {
    }

    onHeightChanged: {

    }

    function addSquareFuild() {

        var newItem = {
            "index": gridModel.count,
            "id": gridModel.count + 1555
        }
        gridModel.append(newItem);
    }

    ListModel {
        id: gridModel
    }

    Component.onCompleted: {
       //Example
        for (var i = 0; i < 20; i++) {
            addSquareFuild();
        }
    }


}


