#include "mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton * pushButton = new QPushButton("Click me", this);
    setCentralWidget(pushButton);

    QAction * quit_acton = new QAction("quit");
    connect(quit_acton, &QAction::triggered, [](){
        QApplication::quit();
    });

    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quit_acton);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");


    statusBar()->showMessage("uploading file....", 5000);
    //statusBar()->showMessage();

}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}

