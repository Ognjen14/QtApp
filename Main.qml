import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
Window {
    id:root
    visible: true
    width: 1920
    height: 1080

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
                width: root.width / 6
                height: root.height / 6
                indexNumber: index + 1
                idNumber: index + 1555
            }
        }
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
        for (var i = 0; i < 10; i++) {
            addSquareFuild();
        }
    }
}


