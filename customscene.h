#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QCursor>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStandardItemModel>
#include <QAbstractItemModel>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

enum class Color{ Green = 1, Blue = 2, Red = 3, White = 4};
enum class STATION{ MOVE = 1, ROTARE=2, RESIZE = 3, CHANGETEXT=4};

class MyShape: public QGraphicsItem
{
    //Q_OBJECT

public:
    MyShape(QGraphicsItem* parent = nullptr);
    QBrush brush = Qt::white;
protected:



    float prevX = -1, prevY = -1;

    bool isSelect = false;

    float glAngle = 0;
    STATION state;
    Color color;

    float m_width = 60;
    float m_height = 60;
    QPointF m_lastPos;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) =0;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};


class Rect: public MyShape
{
public:
    Rect(MyShape* parent = nullptr);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

class Ellipse: public MyShape
{
public:
    Ellipse(MyShape* parent = nullptr);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

class Line: public MyShape
{
public:
    Line(MyShape* parent = nullptr);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class CastomText: public QGraphicsTextItem
{
public:
    CastomText(QGraphicsTextItem* parent = nullptr);
        QString text;
private:
    int prevX = -1;
    int prevY = -1;
    float m_width, m_height;
    STATION state;
    bool isSelect;

    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    //void keyPressEvent(QKeyEvent * event) override;
};


class CustomScene : public QGraphicsScene
{
    Q_OBJECT

public:
    QList<MyShape*> shapes;
    CustomScene(QObject *parent = nullptr);

private:

    Color selectedColor;
    void keyPressEvent(QKeyEvent * event) override;
};

#endif // CUSTOMSCENE_H
