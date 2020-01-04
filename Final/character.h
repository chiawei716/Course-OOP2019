#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QGraphicsPixmapItem>

//Definition of the four directions
#define X_POSITIVE 301
#define X_NEGATIVE 302
#define Y_POSITIVE 303
#define Y_NEGATIVE 304

//Definition of the unit distance (width of one path = unit distance * 2)
#define UNIT_DISTANCE 27



class Character : public QWidget
{
    Q_OBJECT

public:
    Character();
    Character(int x, int y, QLabel *character, QGraphicsItem *parent = nullptr);
    void rendering(QLabel* label1, QLabel* label2);

    //Pure virtual functions
    virtual bool move(Character* pacman = nullptr) = 0;
    virtual bool direction_controlled(QChar key, Character* pacman = nullptr, Character* ghost = nullptr) = 0;
    virtual void pic_change() = 0;

    int x, y;   //position
    int direction;

    //For pacman only
    virtual void button_update(int button){;} 

    //For ghosts
    int scared = 0;
    int start = -1;
    int revive = -1;

protected:

    QMovie* animate;

};

#endif // CHARACTER_H
