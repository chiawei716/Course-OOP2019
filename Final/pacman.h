#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QWidget>
#include "character.h"

#define W_PRESSED 601
#define S_PRESSED 602
#define A_PRESSED 603
#define D_PRESSED 604
#define NOTHING_PRESSED 605

class Pacman : public Character
{
    Q_OBJECT

public:
    Pacman(int x, int y, QLabel *character,QGraphicsItem *parent = nullptr);
    bool direction_controlled(QChar key, Character* pacman = nullptr, Character* ghost = nullptr);
    virtual void pic_change();
    virtual bool move(Character* pacman = nullptr);
    virtual void button_update(int button);
    int button_state;
};

#endif // PACMAN_H
