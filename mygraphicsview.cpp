#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{

    setMinimumHeight(250);
    setMinimumWidth(250);
    setScene(&scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setCacheMode(QGraphicsView::CacheBackground);
    setRenderHints(QPainter::Antialiasing);
    //setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    setOptimizationFlags(QGraphicsView::DontSavePainterState | QGraphicsView::DontAdjustForAntialiasing );
    setFocusPolicy(Qt::StrongFocus);
}

void MyGraphicsView::resizeEvent(QResizeEvent *event) { QGraphicsView::resizeEvent(event); }

void MyGraphicsView::addText()    {scene.addItem(new CastomText(nullptr)); }

void MyGraphicsView::addRect()    {scene.addItem(new Rect(nullptr)); }
void MyGraphicsView::addLine()    {scene.addItem(new Line(nullptr));}
void MyGraphicsView::addEllipse() {scene.addItem(new Ellipse(nullptr));}

void MyGraphicsView::paintGreen(){
    for(auto& item: scene.selectedItems()){
        MyShape *sh = static_cast<MyShape*>(item);
        sh->brush = Qt::green;
    }
}
void MyGraphicsView::paintWhite(){
    for(auto& item: scene.selectedItems()){
        MyShape *sh = static_cast<MyShape*>(item);
        sh->brush = Qt::white;
    }
}
void MyGraphicsView::paintBlue() {
    for(auto& item: scene.selectedItems()){
        MyShape *sh = static_cast<MyShape*>(item);
        sh->brush = Qt::blue;
    }
}
void MyGraphicsView::paintRed()  {
    for(auto& item: scene.selectedItems()){
        MyShape *sh = static_cast<MyShape*>(item);
        sh->brush = Qt::red;
    }
}

void MyGraphicsView::changeText(QString text){
    for(auto& item: scene.selectedItems()){
        CastomText *sh = static_cast<CastomText*>(item);
        sh->text=text;
    }
}


//void MyGraphicsView::paintEvent(QPaintEvent *event){
    //update();
    //QPlainTextEdit::paintEvent(event);
//}

MyGraphicsView::~MyGraphicsView(){
    for (QGraphicsItem *item : scene.items())
        delete item;
    scene.clear();
}
