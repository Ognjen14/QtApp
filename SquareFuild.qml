import QtQuick
import QtQuick.Controls
import SquareObject 1.0
Rectangle {
    id: rectOutside
    property string statusState: "SUSPENDED"
    property string statusColor : "red"
    property real indexNumber : 1
    property real idNumber: 1
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
            text: "Tray 1: ID" + idNumber

        }
        Text {
            anchors
            {
                top: parent.top
                topMargin: 5
                rightMargin: 5
                right: parent.right
            }
            text : indexNumber
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
                text: 0 + " A"
            }
            Text {
                id: detectorCurrentText
                text: 0 + " A"
            }
            Text {
                id: runtimeText
                text: "00:00:00"
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
                text: 0 + " V"
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
    property var startTime : new Date()
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

            runtimeText.text = displayTwoDigits(hours) + ":" + displayTwoDigits(minutes) + ":" + displayTwoDigits(seconds);
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

}

