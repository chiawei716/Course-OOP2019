#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //scene built
    this->scene = new QGraphicsScene(
                    0, 0,
                    ui->graphicsView->width()-2,
                    ui->graphicsView->height()-2
                    );
    ui->graphicsView->setScene(scene);

    //Objects created

    //characters
    Pacman_ch = new Pacman(UNIT_DISTANCE*13+13, UNIT_DISTANCE*23, ui->pacman);
    Blinky_ch = new Blinky(UNIT_DISTANCE*13+13,UNIT_DISTANCE*14, ui->blinky);
    Pinky_ch = new Pinky(UNIT_DISTANCE*13+13,UNIT_DISTANCE*14, ui->pinky);
    Inky_ch = new Inky(UNIT_DISTANCE*13+13,UNIT_DISTANCE*14, ui->inky);
    Clyde_ch = new Clyde(UNIT_DISTANCE*12,UNIT_DISTANCE*14, ui->clyde);

    //qpainter
    qBrush = new QBrush(Qt::yellow);
    qPen.setColor(Qt::yellow);

    //timers
    pacmantimer = new QTimer(this);
    ghost_normal_timer = new QTimer(this);
    ghost_slow_timer = new QTimer(this);
    one_sec = new QTimer(this);

    //Build the dots array
    dots = new bool* [29];
    dots_map = new QGraphicsEllipseItem** [29];
    for(int i = 0; i < 29; i++){
        dots[i] = new bool [26];
        dots_map[i] = new QGraphicsEllipseItem* [26];
    }

    //background rendering
    QPixmap background("./res/map.png");
    scene -> addPixmap(background.scaled(759, 840));    //27:30

    //elements rendering
    Pacman_ch->rendering(ui->pacman, ui->pacman_b);
    Blinky_ch->rendering(ui->blinky, ui->blinky_b);
    Pinky_ch->rendering(ui->pinky, ui->pinky_b);
    Inky_ch->rendering(ui->inky, ui->inky_b);
    Clyde_ch->rendering(ui->clyde, ui->clyde_b);

    dots_ini();
    ui->win->hide();
    ui->lose->hide();
}

//Countdown for the start of the game
void MainWindow::Count_down(){

    count_down--;

    if(count_down > 0){
        char str[1];
        sprintf(str, "%d", count_down);
        ui -> Count_down->setText(str);
    }
    else if(count_down == 0){

        ui -> Count_down->setText("Start");

        pacmantimer->start(10);
        ghost_normal_timer->start(10);
        ghost_slow_timer->start(20);

        disconnect(one_sec, SIGNAL(timeout()), this, SLOT(Count_down()));
        connect(pacmantimer, SIGNAL(timeout()), this, SLOT(pacman_moving()));
        connect(ghost_normal_timer, SIGNAL(timeout()), this, SLOT(characters_normal_moving()));
        connect(ghost_slow_timer, SIGNAL(timeout()), this, SLOT(characters_slow_moving()));
    }

    return;
}

//Initial the dots' position with the map file(.txt)
void MainWindow::dots_ini(){

    //Read the map from the map
    QFile dots_map_f("./res/dots.txt");
    dots_map_f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&dots_map_f);
    QChar temp;
    for(int i = 0; i < 29; i++)
        for(int j = 0; j < 26; j++){
            in >> temp;
            if(temp == '\n') j--;
            else if(temp == '0')
                dots[i][j] = false;
            else if(temp == '1')dots[i][j] = true;
        }

    //Draw the dots
    for(int i = 0; i < 29; i++)
        for(int j = 0; j < 26; j++){
            if(dots[i][j] == true){
                if(j == 0 && i == 2){
                    dots_map[i][j]  = scene -> addEllipse(13+27*(j+1)-6, 13+27*(i+1)-6, 16, 16, qPen, *qBrush);
                }
                else if(j == 25 && i == 2){
                    dots_map[i][j]  = scene -> addEllipse(13+27*(j+1)-6, 13+27*(i+1)-6, 16, 16, qPen, *qBrush);
                }
                else if(j == 0 && i == 22){
                    dots_map[i][j]  = scene -> addEllipse(13+27*(j+1)-6, 13+27*(i+1)-6, 16, 16, qPen, *qBrush);
                }
                else if(j == 25 && i == 22){
                    dots_map[i][j]  = scene -> addEllipse(13+27*(j+1)-6, 13+27*(i+1)-6, 16, 16, qPen, *qBrush);
                }
                else{
                    dots_map[i][j]  = scene -> addEllipse(13+27*(j+1), 13+27*(i+1), 4, 4, qPen, *qBrush);
                }
                dots_map[i][j] -> show();
            }
        }
    return;
};

//Have the dots on the defalut dots_map shown
void MainWindow::Dots_reset(){
    //Read the map from the map
    QFile dots_map_f("./res/dots.txt");
    dots_map_f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&dots_map_f);
    QChar temp;
    for(int i = 0; i < 29; i++)
        for(int j = 0; j < 26; j++){
            in >> temp;
            if(temp == '\n') j--;
            else if(temp == '0')
                dots[i][j] = false;
            else if(temp == '1')dots[i][j] = true;
        }

    //Draw the dots
    for(int i = 0; i < 29; i++)
        for(int j = 0; j < 26; j++){
            if(dots[i][j] == true){
                dots_map[i][j] -> show();
            }
        }

    return;
}

//The SLOT for movement of the pacman
void MainWindow::pacman_moving(){

    //Win of the game
    if(dots_eaten == 246){
        if(high_score < score) high_score = score;
        char score_str[100];
        sprintf(score_str, "%d", high_score);
        ui -> Highscore_score->setText(score_str);
        ui->win->show();
        disconnect(pacmantimer, SIGNAL(timeout()), this, SLOT(pacman_moving()));
        disconnect(ghost_normal_timer, SIGNAL(timeout()), this, SLOT(characters_normal_moving()));
    }
    //Lose the game, or ghost eaten ( Colliding )
    else if(colliding()){
        if(high_score < score) high_score = score;
        char score_str[100];
        sprintf(score_str, "%d", high_score);
        ui -> Highscore_score->setText(score_str);
        ui->lose->show();
        disconnect(pacmantimer, SIGNAL(timeout()), this, SLOT(pacman_moving()));
        disconnect(ghost_normal_timer, SIGNAL(timeout()), this, SLOT(characters_normal_moving()));
    }
    //Common moving case
    else{
        Pacman_ch->move();
        Pacman_ch->rendering(ui->pacman, ui->pacman_b);
        Dots_eaten();
    }

    return;
}

//The SLOT for movement of the ghost in common mode
void MainWindow::characters_normal_moving(){

    //If the ghost are all not frightening
    if(Blinky_ch->scared == 0 && Pinky_ch->scared == 0 && Inky_ch->scared == 0 && Clyde_ch->scared == 0 ){
        Blinky_ch->move(Pacman_ch);
        Pinky_ch->move(Pacman_ch);
        Inky_ch->move(Pacman_ch);
        Clyde_ch->move(Pacman_ch);
        Blinky_ch->rendering(ui->blinky, ui->blinky_b);
        Pinky_ch->rendering(ui->pinky, ui->pinky_b);
        Inky_ch->rendering(ui->inky, ui->inky_b);
        Clyde_ch->rendering(ui->clyde, ui->clyde_b);
    }
    return;
}

//The SLOT for movement of the ghost in frightened mode
void MainWindow::characters_slow_moving(){

    //If there's any ghost is frightening
    if(Blinky_ch->scared != 0 || Pinky_ch->scared != 0 || Inky_ch->scared != 0 || Clyde_ch->scared != 0 ){
        Blinky_ch->move(Pacman_ch);
        Pinky_ch->move(Pacman_ch);
        Inky_ch->move(Pacman_ch);
        Clyde_ch->move(Pacman_ch);
        Blinky_ch->rendering(ui->blinky, ui->blinky_b);
        Pinky_ch->rendering(ui->pinky, ui->pinky_b);
        Inky_ch->rendering(ui->inky, ui->inky_b);
        Clyde_ch->rendering(ui->clyde, ui->clyde_b);
    }
    return;
}

//Check if pacman collides with a ghost
bool MainWindow::colliding(){
    int distance_x, distance_y;

    //With Pinky
    if(Pacman_ch->x > Pinky_ch->x) distance_x = Pacman_ch->x - Pinky_ch->x;
    else distance_x = Pinky_ch->x - Pacman_ch->x;
    if(Pacman_ch->y > Pinky_ch->y) distance_y = Pacman_ch->y - Pinky_ch->y;
    else distance_y = Pinky_ch->y - Pacman_ch->y;
    if(distance_x < 30 && distance_y < 30){
        if(Pinky_ch->scared > 0){
            ghost_eaten(PINKY);
            score += 1000;
            char score_str[100];
            sprintf(score_str, "%d", score);
            ui -> DashBoard_score->setText(score_str);
            return false;
        }
        else return true;
    }

    //With Blinky
    if(Pacman_ch->x > Blinky_ch->x) distance_x = Pacman_ch->x - Blinky_ch->x;
    else distance_x = Blinky_ch->x - Pacman_ch->x;
    if(Pacman_ch->y > Blinky_ch->y) distance_y = Pacman_ch->y - Blinky_ch->y;
    else distance_y = Blinky_ch->y - Pacman_ch->y;
    if(distance_x < 30 && distance_y < 30){
        if(Blinky_ch->scared > 0){
            ghost_eaten(BLINKY);
            score += 1000;
            char score_str[100];
            sprintf(score_str, "%d", score);
            ui -> DashBoard_score->setText(score_str);
        }
        else return true;
    }

    //With Inky
    if(Pacman_ch->x > Inky_ch->x) distance_x = Pacman_ch->x - Inky_ch->x;
    else distance_x = Inky_ch->x - Pacman_ch->x;
    if(Pacman_ch->y > Inky_ch->y) distance_y = Pacman_ch->y - Inky_ch->y;
    else distance_y = Inky_ch->y - Pacman_ch->y;
    if(distance_x < 30 && distance_y < 30){
        if(Inky_ch->scared > 0){
            ghost_eaten(INKY);
            score += 1000;
            char score_str[100];
            sprintf(score_str, "%d", score);
            ui -> DashBoard_score->setText(score_str);
        }
        else return true;
    }

    //With Clyde
    if(Pacman_ch->x > Clyde_ch->x) distance_x = Pacman_ch->x - Clyde_ch->x;
    else distance_x = Clyde_ch->x - Pacman_ch->x;
    if(Pacman_ch->y > Clyde_ch->y) distance_y = Pacman_ch->y - Clyde_ch->y;
    else distance_y = Clyde_ch->y - Pacman_ch->y;
    if(distance_x < 30 && distance_y < 30){
        if(Clyde_ch->scared > 0){
            ghost_eaten(CLYDE);
            score += 1000;
            char score_str[100];
            sprintf(score_str, "%d", score);
            ui -> DashBoard_score->setText(score_str);
        }
        else return true;
    }
    return false;
}

//Situation when a ghost is eaten
void MainWindow::ghost_eaten(int ghost){
    if(ghost == PINKY) Pinky_ch->revive = 381;
    else if(ghost == INKY) Inky_ch->revive = 381;
    else if(ghost == BLINKY) Blinky_ch->revive = 381;
    else if(ghost == CLYDE) Clyde_ch->revive = 381;
}

//Situation when a dot is eaten
void MainWindow::Dots_eaten(){

    //Eat
    if(Pacman_ch -> x % UNIT_DISTANCE == 0 && Pacman_ch -> y % UNIT_DISTANCE == 0 && Pacman_ch->x != 0 && Pacman_ch->x != UNIT_DISTANCE*27){
        if(dots[Pacman_ch -> y/UNIT_DISTANCE -1][Pacman_ch -> x/UNIT_DISTANCE-1] == true){

            //Power Pillet
            if(Pacman_ch -> x / UNIT_DISTANCE == 1 && Pacman_ch -> y / UNIT_DISTANCE == 3){
                Pinky_ch -> scared = 351;
                Blinky_ch -> scared = 351;
                Clyde_ch -> scared = 351;
                Inky_ch -> scared = 351;
                score += 500;
            }
            else if(Pacman_ch -> x / UNIT_DISTANCE == 26 && Pacman_ch -> y / UNIT_DISTANCE == 3){
                Pinky_ch -> scared = 351;
                Blinky_ch -> scared = 351;
                Clyde_ch -> scared = 351;
                Inky_ch -> scared = 351;
                score += 500;
            }
            else if(Pacman_ch -> x / UNIT_DISTANCE == 1 && Pacman_ch -> y / UNIT_DISTANCE == 23){
                Pinky_ch -> scared = 351;
                Blinky_ch -> scared = 351;
                Clyde_ch -> scared = 351;
                Inky_ch -> scared = 351;
                score += 500;
            }
            else if(Pacman_ch -> x / UNIT_DISTANCE == 26 && Pacman_ch -> y / UNIT_DISTANCE == 23){
                Pinky_ch -> scared = 351;
                Blinky_ch -> scared = 351;
                Clyde_ch -> scared = 351;
                Inky_ch -> scared = 351;
                score += 500;
            }

            //Dots
            else{
                score += 100;
            }
            dots_eaten++;
            dots[Pacman_ch -> y/UNIT_DISTANCE-1][Pacman_ch -> x/UNIT_DISTANCE-1] = false;
            dots_map[Pacman_ch -> y/UNIT_DISTANCE-1][Pacman_ch -> x/UNIT_DISTANCE-1]->hide();
            char score_str[100];
            sprintf(score_str, "%d", score);
            ui -> DashBoard_score->setText(score_str);
        }
    }

    return;
}

//Control of PACMAN (create pressing-effect with "isAutoRepeat()" function
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        if(!event->isAutoRepeat() && button_state == NOTHING_PRESSED) button_state = A_PRESSED;
    }
    else if(event->key() == Qt::Key_S){
        if(!event->isAutoRepeat() && button_state == NOTHING_PRESSED) button_state = S_PRESSED;
    }
    else if(event->key() == Qt::Key_W){
        if(!event->isAutoRepeat() && button_state == NOTHING_PRESSED) button_state = W_PRESSED;
    }
    else if(event->key() == Qt::Key_D){
        if(!event->isAutoRepeat() && button_state == NOTHING_PRESSED) button_state = D_PRESSED;
    }

    Pacman_ch -> button_update(button_state);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
       if(!event->isAutoRepeat() && button_state == A_PRESSED) button_state = NOTHING_PRESSED;
    }
    else if(event->key() == Qt::Key_S){
       if(!event->isAutoRepeat() && button_state == S_PRESSED) button_state = NOTHING_PRESSED;
    }
    else if(event->key() == Qt::Key_W){
       if(!event->isAutoRepeat() && button_state == W_PRESSED) button_state = NOTHING_PRESSED;
    }
    else if(event->key() == Qt::Key_D){
       if(!event->isAutoRepeat() && button_state == D_PRESSED) button_state = NOTHING_PRESSED;
    }

    Pacman_ch -> button_update(button_state);
}

//Reset of the game
void MainWindow::on_Start_clicked()
{
    //Disconnect the existing signals
    disconnect(pacmantimer, SIGNAL(timeout()), this, SLOT(pacman_moving()));
    disconnect(ghost_slow_timer, SIGNAL(timeout()), this, SLOT(characters_slow_moving()));
    disconnect(ghost_normal_timer, SIGNAL(timeout()), this, SLOT(characters_normal_moving()));

    //Highscore update
    if(high_score < score) high_score = score;
    char score_str[100];
    sprintf(score_str, "%d", high_score);
    ui -> Highscore_score->setText(score_str);

    //Count down
    count_down = 3;
    char str[2];
    sprintf(str, "%d", count_down);
    ui -> Count_down -> setText(str);
    one_sec -> start(1000);
    connect(one_sec, SIGNAL(timeout()), this, SLOT(Count_down()));

    //Score initiallize
    score = 0;
    sprintf(score_str, "%d", score);
    ui -> DashBoard_score->setText(score_str);

    //Dots initiallize
    Dots_reset();
    dots_eaten = 0;

    //Widgets initiallize
    ui->win->hide();
    ui->lose->hide();

    //Data initiallize
    Pacman_ch->x = UNIT_DISTANCE*13+13;
    Pacman_ch->y =UNIT_DISTANCE*23;
    Pacman_ch->direction = X_POSITIVE;
    Pacman_ch->pic_change();
    Pinky_ch->x = UNIT_DISTANCE*13+13;
    Pinky_ch->y =UNIT_DISTANCE*14;
    Pinky_ch->start = 244;
    Pinky_ch->scared = 0;
    Pinky_ch->revive = -1;
    Inky_ch->x = UNIT_DISTANCE*13+13;
    Inky_ch->y = UNIT_DISTANCE*14;
    Inky_ch->start = 568;
    Inky_ch->scared = 0;
    Inky_ch->revive = -1;
    Blinky_ch->x = UNIT_DISTANCE*13+13;
    Blinky_ch->y =UNIT_DISTANCE*14;
    Blinky_ch->start = 81;
    Blinky_ch->scared = 0;
    Blinky_ch->revive = -1;
    Clyde_ch->x = UNIT_DISTANCE*12;
    Clyde_ch->y = UNIT_DISTANCE*14;
    Clyde_ch->start = 932;
    Clyde_ch->scared = 0;
    Clyde_ch->revive = -1;

    //Rerendering the board
    Pacman_ch->rendering(ui->pacman, ui->pacman_b);
    Blinky_ch->rendering(ui->blinky, ui->blinky_b);
    Pinky_ch->rendering(ui->pinky, ui->pinky_b);
    Inky_ch->rendering(ui->inky, ui->inky_b);
    Clyde_ch->rendering(ui->clyde, ui->clyde_b);
}

MainWindow::~MainWindow()
{
    delete Pacman_ch;
    delete Blinky_ch;
    delete Pinky_ch;
    delete Inky_ch;
    delete Clyde_ch;

    for(int j = 0; j < 29; ++j)
    {
        for(int i = 0; i < 26; ++i)
        {
            delete dots_map[j][i];
        }
        delete[] dots_map[j];
        delete[] dots[j];
    }
    delete[] dots_map;
    delete[] dots;

    delete pacmantimer;
    delete ghost_slow_timer;
    delete ghost_normal_timer;
    delete one_sec;
    
    delete painter;
    delete qBrush;

    delete scene;
    delete ui;
}
