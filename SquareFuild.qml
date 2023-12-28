import QtQuick
import QtQuick.Controls
import SquareObject 1.0
import TcpServer 1.0
import QtQuick.Layouts
Item {
    property string statusState: "SUSPENDED"
    property string statusColor : "red"
    property real indexNumber : 0
    property real idNumber: 1555
    property var startTime: new Date()
    property string runTime : "00:00:00"
    property var  coolerCurrent:[]
    property var  coolerVoltage:[]
    property var  detectorCurrent:[]
    property var  detectorVoltage:[]

    GridLayout {
        id: grid
        rows: 5
        columns: 4
        columnSpacing: 20
        rowSpacing: 20
        anchors.centerIn: parent
        Repeater {
            id: repeaterID
            model: 20 // Here we can control number of SquareObjects(Fuilds) inside matrix!

            Rectangle {
                id: rectOutside
                width: 1920 / 10
                height: 1080 / 10 * 1.7
                color: statusColor
                border.color: "black"
                border.width: 3
                property string statusState: "SUSPENDED"
                property string statusColor : "red"
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

                    /* Text ID Component */
                    Text {
                        anchors
                        {
                            top: parent.top
                            topMargin: 5
                            leftMargin: 5
                            left: parent.left
                        }
                        text: "Tray 1: ID " + 1555 + index

                    }
                    /* Text index Number of SquareFuild */
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

                    /* Column of SquareFuild information */
                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 30
                            leftMargin: 5
                            left: parent.left
                        }

                        Text {
                            text: "Cooler:"
                        }
                        Text {
                            text: "Detector:"
                        }
                        Text {
                            text: "Runtime:"
                        }
                        Text {
                            text: "Rem.time:"
                        }
                    }
                    /* Column of SquareFuild content information */
                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 30
                            leftMargin: 75
                            left: parent.left
                        }

                        Text {
                            id: coolerCurrentText
                            text:   if (coolerCurrent && coolerCurrent[index]) {
                                        return coolerCurrent[index] + " A";
                                    } else {
                                        return "0";
                                    }
                        }
                        Text {
                            id: detectorCurrentText
                            text:   if (detectorCurrent && detectorCurrent[index]) {
                                        return detectorCurrent[index] + " A";
                                    } else {
                                        return "0";
                                    }
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
                     /* Column of SquareFuild content information */
                    Column
                    {
                        anchors {
                            top: parent.top
                            topMargin: 30
                            leftMargin: 125
                            left: parent.left
                        }

                        Text {
                            id:coolerVoltageText
                            text:      if (coolerVoltage && coolerVoltage[index]) {
                                           return coolerVoltage[index] + " V";
                                       } else {
                                           return "0";
                                       }
                        }
                        Text {
                            id: detectorVoltageText
                            text:      if (detectorVoltage && detectorVoltage[index]) {
                                           return detectorVoltage[index] + " V";
                                       } else {
                                           return "0";
                                       }
                        }
                    }

                     /* Row of SquareFuild control buttons*/
                    Row {
                        anchors {
                            bottom: parent.bottom
                            horizontalCenter: parent.horizontalCenter
                            bottomMargin: 5
                        }
                        Button {
                            text: "Run"
                            onClicked: {
                                console.log("Run button clicked for index:", index)
                                repeaterID.itemAt(index).statusState = "RUNNING"
                                repeaterID.itemAt(index).statusColor = "lightgreen"
                            }
                        }
                        Button {
                            text: "Suspend"
                            onClicked: {
                                console.log("Suspend button clicked for index:", index)
                                repeaterID.itemAt(index).statusState = "SUSPENDED"
                                repeaterID.itemAt(index).statusColor = "red"
                            }
                        }
                    }
                }
            }
        }
    }
    /* RunTime Timer */
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

    Receive {
        id: receive

        onMessageReceived: function handleReceivedData(cooler_current, cooler_voltage, detector_current, detector_voltage) {
            coolerCurrent = cooler_current;
            coolerVoltage = cooler_voltage;
            detectorCurrent = detector_current;
            detectorVoltage = detector_voltage;
            printProperties()
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

    function printProperties() {
        console.log("coolerCurrent:");
        for (var i = 0; i < coolerCurrent.length; i++) {
            console.log(coolerCurrent[i]);
        }
        console.log("coolerVoltage:");
        for (var j = 0; j < coolerVoltage.length; j++) {
            console.log(coolerVoltage[j]);
        }
        console.log("detectorCurrent:");
        for (var k = 0; k < detectorCurrent.length; k++) {
            console.log(detectorCurrent[k]);
        }
        console.log("detectorVoltage:");
        for (var m = 0; m < detectorVoltage.length; m++) {
            console.log(detectorVoltage[m]);
        }
    }


}
