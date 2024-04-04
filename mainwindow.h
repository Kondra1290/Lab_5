#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QPushButton>
#include <QLineEdit>


#include "mygraphicsview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QToolBar *toolBar;
    QPushButton *selectText;
    QPushButton *selectRect;
    QPushButton *selectEllipse;
    QPushButton *selectLine;

    QToolBar *colors;
    QPushButton *green;
    QPushButton *red;
    QPushButton *blue;
    QPushButton *white;

    QToolBar *text;
    QLineEdit *line;
    QPushButton *change;

    Ui::MainWindow *ui;
    MyGraphicsView *graphics;
};
#endif // MAINWINDOW_H
