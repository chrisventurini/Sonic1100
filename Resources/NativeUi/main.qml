import QtQuick 2.9
import QtQuick.Window 2.2
import QtWebEngine 1.0

Window {
    visible: true
    width: 640
    height: 480
	WebEngineView {
        anchors.fill: parent
        url: "https://www.qt.io"
    }
}
