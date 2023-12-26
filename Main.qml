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
            model: grid.rows * grid.columns // Here we can control number of SquareObjects(Fuilds) inside matrix!
            SquareFuild{
                width: root.width / 6
                height: root.height / 6
                indexNumber: index + 1
                idNumber: index + 1555
            }
        }
    }
}


