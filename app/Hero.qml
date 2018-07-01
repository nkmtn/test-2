import QtQuick 2.0
//import "qrc:/"

Item {
    id: hero
    width: 48
    height: 48

    property var gameField
    property vector2d direction: Qt.vector2d(1,0)
    property vector2d newDirection: Qt.vector2d(1,0)
    signal exit

    function setCoordinates(x, y)
    {
        hero.x = x
        hero.y = y
    }

    SpriteSequence {
        id: spriteSequence
        width: 48
        height: 48
        interpolate: false

        Sprite {
            name: "right"
            source: "qrc:/img/pacman.png"
            frameCount: 4
            frameDuration: 120
            frameWidth: 48
            frameHeight: 48
            frameX: 0
            frameY: 192
            to: {"right":1}
        }
        Sprite {
            name: "left"
            source: "qrc:/img/pacman.png"
            frameCount: 4
            frameDuration: 120
            frameWidth: 48
            frameHeight: 48
            frameX: 0
            frameY: 96
            to:{"left":1}
        }
        Sprite {
            name: "up"
            source: "qrc:/img/pacman.png"
            frameCount: 4
            frameDuration: 120
            frameWidth: 48
            frameHeight: 48
            frameX: 0
            frameY: 144
            to: {"up":1}
        }
        Sprite {
            name: "down"
            source: "qrc:/img/pacman.png"
            frameCount: 4
            frameDuration: 120
            frameWidth: 48
            frameHeight: 48
            frameX: 0
            frameY: 48
            to: {"down":1}
        }
        Sprite {
            name: "death"
            source: "qrc:/img/pacman.png"
            frameCount: 4
            frameDuration: 120
            frameWidth: 48
            frameHeight: 48
            frameX: 0
            frameY: 0
        }
    }

    Keys.onPressed: {
        //        if (event.isAutoRepeat) {
        //            return;
        //        }

        newDirection = heroController.handle(hero, event, spriteSequence);

        //        switch (event.key) {
        //        case Qt.Key_Left:
        //        case Qt.Key_A:
        //            direction.x = -1
        //            direction.y = 0
        //            r.jumpTo("left")
        //            break;
        //        case Qt.Key_Right:
        //        case Qt.Key_D:
        //            direction.x = 1
        //            direction.y = 0
        //            r.jumpTo("right")
        //            break;
        //        case Qt.Key_Up:
        //        case Qt.Key_W:
        //            direction.x = 0
        //            direction.y = -1
        //            r.jumpTo("up")
        //            break;
        //        case Qt.Key_Down:
        //        case Qt.Key_S:
        //            direction.x = 0
        //            direction.y = 1
        //            r.jumpTo("down")
        //            break;
        //        case Qt.Key_Escape:
        //            exit()
        //        }
    }


    Timer {
        id: timer
        interval: 30
        triggeredOnStart: true
        running: hero.visible
        repeat: true
        property int step: 0
        onTriggered: {
            hero.x += direction.x * 3
            hero.y += direction.y * 3

            step = (step + 1) % 16

            if (step == 0) {
                if (newDirection !== direction)
                    direction = newDirection
                direction = levelManager.handleCollisions(hero, gameField)
                hero.x = (hero.x / 48).toFixed(0) * 48
                hero.y = (hero.y / 48).toFixed(0) * 48
            }

            if (direction.x === 1 && direction.y === 0) spriteSequence.jumpTo("right")
            if (direction.x === -1 && direction.y === 0) spriteSequence.jumpTo("left")
            if (direction.x === 0 && direction.y === 1) spriteSequence.jumpTo("down")
            if (direction.x === 0 && direction.y === -1) spriteSequence.jumpTo("up")

            if(hero.x > 720 - 48) {
                hero.x = -48
            } else if(hero.x < -48) {
                hero.x = 720 - 48
            } if(hero.y > 720 - 48) {
                hero.y = -48
            } else if(hero.y < -48) {
                hero.y = 720 - 48
            }
        }
    }
}

