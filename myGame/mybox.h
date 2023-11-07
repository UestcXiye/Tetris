#ifndef MYBOX_H
#define MYBOX_H

#include <QGraphicsItemGroup>
#include <QGraphicsObject>

// 小方块类
class OneBox : public QGraphicsObject
{
private:
    QColor brushColor;

public:
    OneBox(const QColor& color = Qt::red);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QPainterPath shape() const;
};

// 方块组类
class BoxGroup : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    enum BoxShape
    {
        IShape,
        JShape,
        LShape,
        OShape,
        SShape,
        TShape,
        ZShape,
        RandomShape
    };

    BoxGroup();
    QRectF boundingRect() const;

    bool isColliding();
    void createBox(const QPointF& point = QPointF(0, 0), BoxShape shape = RandomShape);
    void clearBoxGroup(bool destroyBox = false);
    BoxShape getCurrentShape() { return currentShape; }

private:
    BoxShape currentShape;
    QTransform oldTransform;
    QTimer* timer;

protected:
    void keyPressEvent(QKeyEvent* event);

signals:
    void needNewBox();
    void gameFinished();

public slots:
    void moveOneStep();
    void startTimer(int interval);
    void stopTimer();
};
#endif  // MYBOX_H
