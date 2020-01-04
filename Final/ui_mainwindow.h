/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QLabel *pacman_b;
    QLabel *pacman;
    QLabel *blinky;
    QLabel *blinky_b;
    QLabel *pinky;
    QLabel *pinky_b;
    QLabel *inky_b;
    QLabel *inky;
    QLabel *clyde;
    QLabel *clyde_b;
    QLabel *DashBoard_title;
    QLabel *DashBoard_score;
    QLabel *win;
    QLabel *lose;
    QPushButton *Start;
    QLabel *Count_down;
    QLabel *Highscore_score;
    QLabel *Highscore_title;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 850);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 761, 842));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 761, 842));
        pacman_b = new QLabel(widget);
        pacman_b->setObjectName(QStringLiteral("pacman_b"));
        pacman_b->setGeometry(QRect(630, 60, 91, 50));
        pacman = new QLabel(widget);
        pacman->setObjectName(QStringLiteral("pacman"));
        pacman->setGeometry(QRect(630, 130, 81, 50));
        blinky = new QLabel(widget);
        blinky->setObjectName(QStringLiteral("blinky"));
        blinky->setGeometry(QRect(630, 200, 91, 50));
        blinky_b = new QLabel(widget);
        blinky_b->setObjectName(QStringLiteral("blinky_b"));
        blinky_b->setGeometry(QRect(630, 270, 91, 50));
        pinky = new QLabel(widget);
        pinky->setObjectName(QStringLiteral("pinky"));
        pinky->setGeometry(QRect(630, 330, 91, 50));
        pinky_b = new QLabel(widget);
        pinky_b->setObjectName(QStringLiteral("pinky_b"));
        pinky_b->setGeometry(QRect(630, 400, 91, 50));
        inky_b = new QLabel(widget);
        inky_b->setObjectName(QStringLiteral("inky_b"));
        inky_b->setGeometry(QRect(630, 540, 91, 50));
        inky = new QLabel(widget);
        inky->setObjectName(QStringLiteral("inky"));
        inky->setGeometry(QRect(630, 470, 91, 50));
        clyde = new QLabel(widget);
        clyde->setObjectName(QStringLiteral("clyde"));
        clyde->setGeometry(QRect(630, 610, 91, 50));
        clyde_b = new QLabel(widget);
        clyde_b->setObjectName(QStringLiteral("clyde_b"));
        clyde_b->setGeometry(QRect(630, 680, 91, 50));
        DashBoard_title = new QLabel(centralWidget);
        DashBoard_title->setObjectName(QStringLiteral("DashBoard_title"));
        DashBoard_title->setGeometry(QRect(800, 0, 171, 81));
        QFont font;
        font.setPointSize(20);
        DashBoard_title->setFont(font);
        DashBoard_score = new QLabel(centralWidget);
        DashBoard_score->setObjectName(QStringLiteral("DashBoard_score"));
        DashBoard_score->setGeometry(QRect(790, 70, 161, 61));
        QFont font1;
        font1.setPointSize(35);
        DashBoard_score->setFont(font1);
        DashBoard_score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        win = new QLabel(centralWidget);
        win->setObjectName(QStringLiteral("win"));
        win->setGeometry(QRect(0, 0, 771, 852));
        QFont font2;
        font2.setPointSize(100);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        win->setFont(font2);
        win->setAutoFillBackground(true);
        win->setAlignment(Qt::AlignCenter);
        lose = new QLabel(centralWidget);
        lose->setObjectName(QStringLiteral("lose"));
        lose->setGeometry(QRect(0, 0, 771, 852));
        lose->setFont(font2);
        lose->setAutoFillBackground(true);
        lose->setAlignment(Qt::AlignCenter);
        Start = new QPushButton(centralWidget);
        Start->setObjectName(QStringLiteral("Start"));
        Start->setGeometry(QRect(790, 380, 200, 100));
        Start->setFont(font);
        Count_down = new QLabel(centralWidget);
        Count_down->setObjectName(QStringLiteral("Count_down"));
        Count_down->setGeometry(QRect(850, 650, 100, 100));
        QFont font3;
        font3.setPointSize(30);
        Count_down->setFont(font3);
        Count_down->setAlignment(Qt::AlignCenter);
        Highscore_score = new QLabel(centralWidget);
        Highscore_score->setObjectName(QStringLiteral("Highscore_score"));
        Highscore_score->setGeometry(QRect(790, 200, 161, 61));
        Highscore_score->setFont(font1);
        Highscore_score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Highscore_title = new QLabel(centralWidget);
        Highscore_title->setObjectName(QStringLiteral("Highscore_title"));
        Highscore_title->setGeometry(QRect(800, 130, 171, 81));
        Highscore_title->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pacman_b->setText(QApplication::translate("MainWindow", "PACMAN_B", 0));
        pacman->setText(QApplication::translate("MainWindow", "PACMAN", 0));
        blinky->setText(QApplication::translate("MainWindow", "BLINKY", 0));
        blinky_b->setText(QApplication::translate("MainWindow", "BLINKY_B", 0));
        pinky->setText(QApplication::translate("MainWindow", "PINKY", 0));
        pinky_b->setText(QApplication::translate("MainWindow", "PINKY_B", 0));
        inky_b->setText(QApplication::translate("MainWindow", "INKY_B", 0));
        inky->setText(QApplication::translate("MainWindow", "INKY", 0));
        clyde->setText(QApplication::translate("MainWindow", "CLYDE", 0));
        clyde_b->setText(QApplication::translate("MainWindow", "CLYDE_B", 0));
        DashBoard_title->setText(QApplication::translate("MainWindow", "SCORE:", 0));
        DashBoard_score->setText(QApplication::translate("MainWindow", "0", 0));
        win->setText(QApplication::translate("MainWindow", "WIN", 0));
        lose->setText(QApplication::translate("MainWindow", "LOSE", 0));
        Start->setText(QApplication::translate("MainWindow", "StartNewGame", 0));
        Count_down->setText(QString());
        Highscore_score->setText(QApplication::translate("MainWindow", "0", 0));
        Highscore_title->setText(QApplication::translate("MainWindow", "HIGH SCORE:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
