import QtQuick 2.0

Image {
    width: 720
    height: 480
    source:"background.jpg"

    Image {
        id: top
        width: 550
        height: 90
        source:"contr.png"
        Rectangle{
            anchors.fill: parent
            color:"#00000000"

            border.color:"black"
            border.width: 3
        }
    }

    Image{
        id:right
        x:550
        width:165
        height: 450
        source:"left.png"
        Rectangle{
            anchors.fill: parent
            color:"#00000000"
            border.color: "black"
            border.width: 3
        }
    }


    Image{
        id:centerWindow
        y:100
        x: 15
        width:520
        height:260
        source:"watch.jpg"

        Rectangle{
            anchors.fill: parent
            color:"#00000000"
            border.color: "black"
            border.width: 3
        }  
    }




    Image{
        id:plusButton
        x: 21
        y: 162
        width:50
        height: 70
        source:"plus.png"

    }

    Image{
        id:minusButton
        x: 21
        y: 295
        width:50
        height: 70
        source:"minus.png"
    }


    Grid{
        y:375
        x:30
        columns: 5
        spacing: 22

        Image{
            width: 80
            height: 80
            source: "yt.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    centerWindow.source = "youtube.png"
                    plusButton.visible = false
                    minusButton.visible = false
                }
            }

        }
        Image{
            width: 80
            height: 80
            source: "map.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    centerWindow.source = "main.jpg"
                    plusButton.visible = true
                    minusButton.visible = true

                }
            }
        }
        Image{
            width: 80
            height: 80
            source: "time.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {

                    centerWindow.source = "watch.jpg"
                    plusButton.visible = false
                    minusButton.visible = false


                }
            }
        }
        Image{
            width: 80
            height: 80
            source: "gmail.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    centerWindow.source = "gmailbox.png"
                    plusButton.visible = false
                    minusButton.visible = false
                }
            }
        }
        Image{
            width: 80
            height: 80
            source: "phone.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    centerWindow.source = "calling.jpg"
                    plusButton.visible = false
                    minusButton.visible = false

                }
            }
        }

    }
}
