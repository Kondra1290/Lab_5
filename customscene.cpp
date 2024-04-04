#include "customscene.h"

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setSceneRect(0, 0, 500, 500);
    setItemIndexMethod(QGraphicsScene::NoIndex);
}
void CustomScene::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Backspace) {
        if(!selectedItems().isEmpty()) {
            for(auto& item: selectedItems()){
                removeItem(item);
                delete item;
            }

        }
    }
    else {
        QGraphicsScene::keyPressEvent(event);
    }
}

MyShape::MyShape(QGraphicsItem* parent): QGraphicsItem(parent)
{
    state = STATION::MOVE;
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF MyShape::boundingRect() const    { return QRectF(-m_width/2, -m_height/2, m_width, m_height).normalized(); }

void MyShape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)  {
    if(static_cast<int>(state) == 1){
        prepareGeometryChange();
        this->setPos(mapToScene(event->pos()));
     }
    else if (static_cast<int>(state) == 2){
        auto angle = qRadiansToDegrees(qAtan2(event->pos().y(), event->pos().x()));
        setRotation(rotation() + angle);
    }
    else if (static_cast<int>(state) == 3){
        if(prevX != -1 && prevY != -1)
        {
            float x = mapToScene(event->pos()).x();
            float y = mapToScene(event->pos()).y();
            float dx = (x - prevX);
            float dy = (y - prevY);

            prepareGeometryChange();
            m_width  = x > 0 ? m_width + dx: m_width - dx;
            m_height = y > 0 ? m_height + dy: m_height - dy;
        }
        prevX = mapToScene(event->pos()).x();
        prevY = mapToScene(event->pos()).y();
    }
}

void MyShape::mousePressEvent(QGraphicsSceneMouseEvent *event)  {
    if(event->buttons() & Qt::LeftButton){
        setCursor(QCursor(Qt::ClosedHandCursor));
    }
    else{
        prevX = -1;
        prevY = -1;
    }
}

void MyShape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){ this->setCursor(QCursor(Qt::ArrowCursor)); }
void MyShape::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){

    if(event->type() == QEvent::GraphicsSceneMouseDoubleClick){
        if (event->button() == Qt::LeftButton)
            if      (static_cast<int>(state) == 1) { state = STATION::ROTARE; }
            else if (static_cast<int>(state) == 2) { state = STATION::RESIZE; }
            else                                   { state = STATION::MOVE;   }
        else if(event->button() == Qt::RightButton){
            isSelect = !isSelect;
            setSelected(isSelect);
        }
    }
}

Ellipse::Ellipse(MyShape* parent)
    : MyShape(parent)
{
    m_width = 60;
    m_height = 60;
    setPos(200, 200);
}
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isSelected()) painter->setPen(Qt::red);
    else painter->setPen(Qt::black);
    painter->setBrush(brush);
    painter->drawEllipse(-m_width/2, -m_height/2, m_width, m_height);
    update();
}

Rect::Rect(MyShape* parent): MyShape(parent)
{
    m_width = 60;
    m_height = 60;
    setPos(200, 200);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isSelected()) painter->setPen(Qt::red);
    else painter->setPen(Qt::black);
    painter->setBrush(brush);
    painter->drawRect(-m_width/2, -m_height/2, m_width, m_height);
    update();
}

Line::Line(MyShape* parent)
    : MyShape(parent)
{
    m_width = 60;
    m_height = 60;
    setPos(200, 200);
}
void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (isSelected()) painter->setPen(Qt::red);
    else painter->setPen(Qt::black);
    painter->drawLine(-m_width/2, -m_height/2, m_width, m_height);
    update();
}



CastomText::CastomText(QGraphicsTextItem* parent):
    QGraphicsTextItem(parent)
{
    m_width = 80;
    m_height = 50;
    setPos(200, 200);
    text = "Новый текст";
    setTextWidth(24);
    state = STATION::MOVE;
    setTextInteractionFlags(Qt::TextEditorInteraction | Qt::TextEditable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF CastomText::boundingRect() const{
    return QRectF(-m_width/2, -m_height/2, m_width, m_height).normalized();
}
void CastomText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if (isSelected()) painter->setPen(Qt::red);
    else painter->setPen(Qt::black);
    painter->drawText(boundingRect(), Qt::AlignCenter, text);
    update();
}

void CastomText::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){ this->setCursor(QCursor(Qt::ArrowCursor)); }
void CastomText::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(static_cast<int>(state) == 1){
        prepareGeometryChange();
        this->setPos(mapToScene(event->pos()));
    }
    else if (static_cast<int>(state) == 2){
        auto angle = qRadiansToDegrees(qAtan2(event->pos().y(), event->pos().x()));
        setRotation(rotation() + angle);
    }
    else if (static_cast<int>(state) == 3){
        if(prevX != -1 && prevY != -1)
        {
            float x = mapToScene(event->pos()).x();
            float y = mapToScene(event->pos()).y();
            float dx = (x - prevX);
            float dy = (y - prevY);

            prepareGeometryChange();
            m_width  = x > 0 ? m_width + dx: m_width - dx;
            m_height = y > 0 ? m_height + dy: m_height - dy;
        }
        prevX = mapToScene(event->pos()).x();
        prevY = mapToScene(event->pos()).y();
    }
}
void CastomText::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        setCursor(QCursor(Qt::ClosedHandCursor));
    }
    else{
        prevX = -1;
        prevY = -1;
    }
}

void CastomText::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    if(event->type() == QEvent::GraphicsSceneMouseDoubleClick){
        if(event->button() == Qt::LeftButton){
            isSelect = !isSelect;
            setSelected(isSelect);
            setFocus();

        }
    }
}
