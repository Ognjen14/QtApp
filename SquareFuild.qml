import QtQuick
import QtQuick.Controls
import SquareObject 1.0
import TcpServer 1.0
import QtQuick.Layouts
Item {
    property string statusState: "SUSPENDED"
    property string statusColor : "red"
    property real indexNumber : 1
    property real idNumber: 1555
    property var startTime: new Date()
    property string runTime : "00:00:00"
    property real  coolerCurrent: 0
    property real  coolerVoltage: 0


    GridLayout {
        id: grid
        rows: 5
        columns: 4
        columnSpacing: 20
        rowSpacing: 20
        anchors.centerIn: parent
        Repeater {
            model: 20 // Here we can control number of SquareObjects(Fuilds) inside matrix!

            Rectangle {
                id: rectOutside
                width: 1920 / 10
                height: 1080 / 10 * 1.7
                color: statusColor
                border.color: "black"
                border.width: 3

                Text
                {
                    anchors.top: parent.top
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: statusState
                    font.bold: true
                }
                Rectangle {
                    id: rectInside
                    anchors.centerIn: parent
                    width: parent.width - 25
                    height: parent.height - 25
                    color: "white"
                    border.color: "black"
                    border.width: 3

                    Text {
                        anchors
                        {
                            top: parent.top
                            topMargin: 5
                            leftMargin: 5
                            left: parent.left
                        }
                        text: "Tray 1: ID" + index + 1555

                    }
                    Text {
                        anchors
                        {
                            top: parent.top
                            topMargin: 5
                            rightMargin: 5
                            right: parent.right
                        }
                        text : indexNumber + index + 1
                        font.pixelSize: 22
                        font.bold : true
                    }

                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 25
                            leftMargin: 5
                            left: parent.left
                        }

                        Text {
                            text: "Cooler:"
                        }
                        Text {
                            text: "Detectir:"
                        }
                        Text {
                            text: "Runtime:"
                        }
                        Text {
                            text: "Rem.time:"
                        }
                    }
                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 25
                            leftMargin: 75
                            left: parent.left
                        }

                        Text {
                            id: coolerCurrentText
                            text: coolerCurrent+ " A"
                        }
                        Text {
                            id: detectorCurrentText
                            text: 0 + " A"
                        }
                        Text {
                            id: runtimeText
                            text:  runTime
                        }
                        Text {
                            id: remtimeText
                            text: "00:00:00"
                        }
                    }
                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 25
                            leftMargin: 125
                            left: parent.left
                        }

                        Text {
                            id:coolerVoltageText
                            text: coolerVoltage + " V"
                        }
                        Text {
                            id: detectorVoltageText
                            text: 0 + " V"
                        }
                    }

                    Row {
                        anchors {
                            bottom: parent.bottom
                            horizontalCenter: parent.horizontalCenter
                            bottomMargin: 5
                        }
                        Button {
                            text: "Run"
                            onClicked: {
                                console.log("Run button clicked")
                                statusState = "RUNNING"
                                statusColor = "lightgreen"

                            }
                        }
                        Button {
                            text: "Suspend"
                            onClicked: {

                                console.log("Suspend button clicked")
                                statusState = "SUSPENDED"
                                statusColor = "red"

                            }
                        }
                    }
                }
            }
        }
    }
    Timer {
        id: timerRunTime
        interval: 1000
        running: true
        repeat: true
        onTriggered: {
            var currentTime = new Date();
            var elapsedSeconds = Math.floor((currentTime.getTime() - startTime.getTime()) / 1000);

            var hours = Math.floor(elapsedSeconds / 3600);
            var minutes = Math.floor((elapsedSeconds % 3600) / 60);
            var seconds = elapsedSeconds % 60;

            runTime = displayTwoDigits(hours) + ":" + displayTwoDigits(minutes) + ":" + displayTwoDigits(seconds);
        }
    }

    function displayTwoDigits(number) {
        return (number < 10) ? "0" + number : number;
    }

    SquareObjectInfo
    {
        onBorderColorChanged:
        {
            rectOutside.color = borderColor
        }
        onCoolerCurrentChanged:
        {
            coolerCurrentText.text = coolerCurrent
        }
        onCoolerVoltageChanged:
        {
            coolerVoltageText.text = coolerVoltage
        }
        onDetectorCurrentChanged:
        {
            detectorCurrentText.text = detectorCurrent

        }
        onDetectorVoltageChanged:
        {
            detectorVoltageText.text = detectorVoltage
        }
    }
    Component.onCompleted: {
        //Example
        for (var i = 0; i < 20; i++) {
            addSquareFuild();
        }
        receive.startServer(1234)
    }
    Receive
    {
        id: receive
        onMessageReceived:
        {
            coolerCurrent = current
            coolerVoltage = voltage
            console.log(current)
        }
    }

    /* Probably wont be nessesery to have this */
    function addSquareFuild() {

        var newItem = {
            "index": gridModel.count,
            "id": gridModel.count + 1555
        }
        gridModel.append(newItem);
    }
    /* Probably wont be nessesery to have this */
    ListModel {
        id: gridModel
    }


}
