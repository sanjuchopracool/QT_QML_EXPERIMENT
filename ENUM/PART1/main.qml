import QtQuick 2.9
import QtQuick.Window 2.2
import com.chops.sanjay 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Animal {

    }

    Component.onCompleted:
    {
        var item = Animal.Birds
    }
}
