#include "pacman.h"
#include "character.h"

Pacman::Pacman(int x, int y, QLabel *character,QGraphicsItem *parent) : Character(x, y, character, parent)
{
    direction = X_POSITIVE;
    button_state = NOTHING_PRESSED;

    animate = new QMovie(":/img/pacman_moving_rightward.gif");
    character->setMovie(animate);
    animate->setScaledSize(QSize(50, 50));
    animate -> start();

}


//Change the direction of the pacman with buttons.   ***ONLY AT CORNER***
//Method: Button presseing -> Check if is at a corner -> Change direction
bool Pacman::direction_controlled(QChar key, Character* pacman , Character* ghost){
    if(key == 'A' && direction != X_NEGATIVE){
        if(direction == X_POSITIVE){
            direction = X_NEGATIVE;
            return true;
        }
        else if(x == UNIT_DISTANCE*3){
            if(y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*6){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*26){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*9){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*12){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26 || y==UNIT_DISTANCE*29){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*15){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*29){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*18){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*17 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*21){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*24){
            if(y==UNIT_DISTANCE*26){
                direction = X_NEGATIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*26){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26 || y==UNIT_DISTANCE*29){
                direction = X_NEGATIVE;
                return true;
            }
        }
    }
    else if(key == 'D' && direction != X_POSITIVE){
        if(direction == X_NEGATIVE){
            direction = X_POSITIVE;
            return true;
        }
        else if(x == UNIT_DISTANCE*24){
            if(y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*21){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*26){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*18){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*15){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26 || y==UNIT_DISTANCE*29){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*12){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*29){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*9){
            if(y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*11 || y==UNIT_DISTANCE*17 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*6){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*14 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*3){
            if(y==UNIT_DISTANCE*26){
                direction = X_POSITIVE;
                return true;
            }
        }
        else if(x == UNIT_DISTANCE*1){
            if(y==UNIT_DISTANCE*1 || y==UNIT_DISTANCE*5 || y==UNIT_DISTANCE*8 || y==UNIT_DISTANCE*20 || y==UNIT_DISTANCE*23 || y==UNIT_DISTANCE*26 || y==UNIT_DISTANCE*29){
                direction = X_POSITIVE;
                return true;
            }
        }
    }
    else if(key == 'W' && direction != Y_NEGATIVE){
        if(direction == Y_POSITIVE){
            direction = Y_NEGATIVE;
            return true;
        }
        else if(y == UNIT_DISTANCE*5){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*26){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*8){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*26){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*11){
            if(x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*14){
            if(x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*17){
            if(x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*20){
            if(x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*23){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*26){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*26){
            if(x==UNIT_DISTANCE*3 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*24){
                direction = Y_NEGATIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*29){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*26){
                direction = Y_NEGATIVE;
                return true;
            }
        }
    }
    else if(key == 'S' && direction != Y_POSITIVE){
        if(direction == Y_NEGATIVE){
            direction = Y_POSITIVE;
            return true;
        }
        else if(y == UNIT_DISTANCE*1){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*26){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*5){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*26){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*8){
            if(x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*21){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*11){
            if(x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*14){
            if(x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*17){
            if(x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*20){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*21 ||x==UNIT_DISTANCE*26){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*23){
            if(x==UNIT_DISTANCE*3 || x==UNIT_DISTANCE*6 || x==UNIT_DISTANCE*9 || x==UNIT_DISTANCE*18 || x==UNIT_DISTANCE*21 || x==UNIT_DISTANCE*24){
                direction = Y_POSITIVE;
                return true;
            }
        }
        else if(y == UNIT_DISTANCE*26){
            if(x==UNIT_DISTANCE*1 || x==UNIT_DISTANCE*12 || x==UNIT_DISTANCE*15 || x==UNIT_DISTANCE*26){
                direction = Y_POSITIVE;
                return true;
            }
        }
    }
    return false;
}

//Change the GIF picture according to the direction pacman moves.
void Pacman::pic_change(){

    //Stop the QMovie
    animate->stop();

    //Change the GIF file according to direction
    if(direction == X_NEGATIVE)
        animate -> setFileName(":/img/pacman_moving_leftward.gif");
    else if(direction == X_POSITIVE)
        animate -> setFileName(":/img/pacman_moving_rightward.gif");
    else if(direction == Y_NEGATIVE)
        animate -> setFileName(":/img/pacman_moving_upward.gif");
    else if(direction == Y_POSITIVE)
        animate -> setFileName(":/img/pacman_moving_downward.gif");

    //Restart the QMovie
    animate->start();
}

//Direction change / Moving availibility
bool Pacman::move(Character* pacman){

    //Check if a button is pressed, and change its direction if so
    if(button_state == A_PRESSED){
        if(direction_controlled('A'))
            pic_change();
    }
    else if(button_state == W_PRESSED){
        if(direction_controlled('W'))
            pic_change();
    }
    else if(button_state == S_PRESSED){
        if(direction_controlled('S'))
            pic_change();
    }
    else if(button_state == D_PRESSED){
        if(direction_controlled('D'))
            pic_change();
    }

    //Moving with checked/changed direction

    //through the map
    if(x >= 744) x -= 759;
    else if(x <= -15) x += 759;

    //common case (check if it is stucked in front of a wall, or move)
    if(direction == X_NEGATIVE){
        if(y == UNIT_DISTANCE*1){
            if(x != UNIT_DISTANCE*1 && x != UNIT_DISTANCE*15){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*5){
            if(x != UNIT_DISTANCE*1){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*8){
            if(x != UNIT_DISTANCE*1 && x != UNIT_DISTANCE*9 && x != UNIT_DISTANCE*15 && x != UNIT_DISTANCE*21){
                x--; return true;
            }
        }
        else if(y == UNIT_DISTANCE*11){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*9 && x != UNIT_DISTANCE*21){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*14){
            if(x != UNIT_DISTANCE*18){ x--; return true;}
        }
        else if(y ==UNIT_DISTANCE*17){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*9 && x!= UNIT_DISTANCE*21){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*20){
            if(x != UNIT_DISTANCE*1 && x != UNIT_DISTANCE*15){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*23){
            if(x != UNIT_DISTANCE*1 && x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*24){ x--; return true;}
        }
        else if(y == UNIT_DISTANCE*26){
            if(x != UNIT_DISTANCE*1 && x != UNIT_DISTANCE*9 && x != UNIT_DISTANCE*15 && x != UNIT_DISTANCE*21){
                x--; return true;
            }
        }
        else if(y == UNIT_DISTANCE*29){
            if(x != UNIT_DISTANCE*1){ x--; return true;}
        }
    }
    else if(direction == X_POSITIVE){
        if(y == UNIT_DISTANCE*1){
            if(x != UNIT_DISTANCE*12 && x != UNIT_DISTANCE*26){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*5){
            if(x != UNIT_DISTANCE*26){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*8){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*12 && x != UNIT_DISTANCE*18 && x != UNIT_DISTANCE*26){
                x++; return true;
            }
        }
        else if(y == UNIT_DISTANCE*11){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*18 && x != UNIT_DISTANCE*21){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*14){
            if(x != UNIT_DISTANCE*9){ x++; return true;}
        }
        else if(y ==UNIT_DISTANCE*17){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*18 && x!= UNIT_DISTANCE*21){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*20){
            if(x != UNIT_DISTANCE*12 && x != UNIT_DISTANCE*26){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*23){
            if(x != UNIT_DISTANCE*3 && x != UNIT_DISTANCE*21 && x != UNIT_DISTANCE*26){ x++; return true;}
        }
        else if(y == UNIT_DISTANCE*26){
            if(x != UNIT_DISTANCE*6 && x != UNIT_DISTANCE*12 && x != UNIT_DISTANCE*18 && x != UNIT_DISTANCE*26){
                x++; return true;
            }
        }
        else if(y == UNIT_DISTANCE*29){
            if(x != UNIT_DISTANCE*26){ x++; return true;}
        }
    }
    else if(direction == Y_NEGATIVE){
        if(x == UNIT_DISTANCE*1 || x == UNIT_DISTANCE*26){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*14 && y != UNIT_DISTANCE*20 && y != UNIT_DISTANCE*26){
                y--; return true;
            }
        }
        else if(x == UNIT_DISTANCE*3 || x == UNIT_DISTANCE*24){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*5 && y!= UNIT_DISTANCE*8 && y != UNIT_DISTANCE*14 && y != UNIT_DISTANCE*20 && y != UNIT_DISTANCE*23 && y != UNIT_DISTANCE*29){
                y--; return true;
            }
        }
        else if(x == UNIT_DISTANCE*6 || x == UNIT_DISTANCE*21){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*29){ y--; return true;}
        }
        else if(x == UNIT_DISTANCE*9 || x == UNIT_DISTANCE*18){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*5 && y != UNIT_DISTANCE*11 && y != UNIT_DISTANCE*23 && y != UNIT_DISTANCE*29){
                y--; return true;
            }
        }
        else if(x == UNIT_DISTANCE*12 || x == UNIT_DISTANCE*15){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*8 && y != UNIT_DISTANCE*17 && y != UNIT_DISTANCE*20 && y != UNIT_DISTANCE*26){
                y--; return true;
            }
        }
    }
    else if(direction == Y_POSITIVE){
        if(x == UNIT_DISTANCE*1 || x == UNIT_DISTANCE*26){
            if(y != UNIT_DISTANCE*8 && y != UNIT_DISTANCE*14 && y != UNIT_DISTANCE*23 && y != UNIT_DISTANCE*29){
                y++; return true;
            }
        }
        else if(x == UNIT_DISTANCE*3 || x == UNIT_DISTANCE*24){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*5 && y!= UNIT_DISTANCE*8 && y != UNIT_DISTANCE*14 && y != UNIT_DISTANCE*20 && y != UNIT_DISTANCE*26 && y != UNIT_DISTANCE*29){
                y++; return true;
            }
        }
        else if(x == UNIT_DISTANCE*6 || x == UNIT_DISTANCE*21){
            if(y != UNIT_DISTANCE*26 && y != UNIT_DISTANCE*29){ y++; return true;}
        }
        else if(x == UNIT_DISTANCE*9 || x == UNIT_DISTANCE*18){
            if(y != UNIT_DISTANCE*1 && y != UNIT_DISTANCE*8 && y != UNIT_DISTANCE*20 && y != UNIT_DISTANCE*26 && y != UNIT_DISTANCE*29){
                y++; return true;
            }
        }
        else if(x == UNIT_DISTANCE*12 || x == UNIT_DISTANCE*15){
            if(y != UNIT_DISTANCE*5 && y != UNIT_DISTANCE*11 && y != UNIT_DISTANCE*17 && y != UNIT_DISTANCE*23 && y != UNIT_DISTANCE*29){
                y++; return true;
            }
        }
    }

    return false;
}

//Change the button pressed or none
void Pacman::button_update(int button){
    button_state = button;
    return;
}
