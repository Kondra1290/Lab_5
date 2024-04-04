#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QResizeEvent>
#include <QGraphicsView>
#include "customscene.h"

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget *parent = nullptr);
    void addText();
    void addRect();
    void addEllipse();
    void addLine();

    void paintGreen();
    void paintBlue();
    void paintRed();
    void paintWhite();

    void changeText(QString text);
    ~ MyGraphicsView();

private:

    QList<QGraphicsItem *> items;
    CustomScene scene;
    void resizeEvent(QResizeEvent *event) override;
    //void paintEvent(QPaintEvent *event) override;
};

#endif // MYGRAPHICSVIEW_H
