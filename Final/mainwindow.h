#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QFile>
#include "character.h"
#include "pacman.h"
#include "inky.h"
#include "blinky.h"
#include "pinky.h"
#include "clyde.h"

#define NONE -1
#define PINKY 0
#define INKY 1
#define BLINKY 2
#define CLYDE 3


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //Game
    int score = 0;
    int high_score = 0;
    int button_state = NOTHING_PRESSED;

    //Countdown
    QTimer *pacmantimer, *ghost_slow_timer, *ghost_normal_timer, *one_sec;
    int count_down = 5;

    //Characters
    Character *Pacman_ch, *Blinky_ch, *Pinky_ch, *Inky_ch, *Clyde_ch;
    void ghost_eaten(int ghost);
    bool colliding();

    //QPainter
    QPainter* painter;
    QBrush* qBrush;
    QPen qPen;

    //Dots
    QGraphicsEllipseItem*** dots_map;
    int dots_eaten = 0;
    bool** dots;
    void dots_ini();
    void Dots_eaten();
    void Dots_reset();

private slots:
    void characters_normal_moving();
    void characters_slow_moving();
    void pacman_moving();
    void Count_down();
    void on_Start_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
