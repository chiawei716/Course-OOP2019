#include "character.h"

Character::Character(){;}

Character::Character(int x, int y, QLabel *character,QGraphicsItem *parent)
{
    this->x = x;
    this->y = y;
}

//Update the position of the characters' pictures
void Character::rendering(QLabel *character, QLabel *character_b){

    //Set the position of the character itself
    character->setGeometry(x-10, y-10, 50, 50);

    //If out of the border, set the second picture
    if(x <= 0 || x >= 729){
        if(x <= 0) character_b->setGeometry(x + 749, y-10, 50, 50);
        else if(x >=729) character_b->setGeometry(x - 769, y-10, 50, 50);
        character_b->show();
        character_b->setMovie(animate);
    }
    else character_b->hide();

    return;
}
