#include "mybox.h"

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

// 小方块类

OneBox::OneBox(const QColor& color) { brushColor = color; }

QRectF OneBox::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);
}

void OneBox::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // 为小方块使用贴图
    painter->drawPixmap(-10, -10, 20, 20, QPixmap(":/images/box.gif"));
    painter->setBrush(brushColor);

    QColor penColor = brushColor;
    // 将颜色的透明度降低
    penColor.setAlpha(20);
    painter->setPen(penColor);
    painter->drawRect(-10, -10, 20, 20);
}

QPainterPath OneBox::shape() const
{
    QPainterPath path;
    // 形状比边框矩形小 0.5 像素，这样方块组中的小方块才不会发生碰撞
    path.addRect(-9.5, -9.5, 19, 19);
    return path;
}

// 方块组类

void BoxGroup::keyPressEvent(QKeyEvent* event)
{
    qreal oldRotate;

    switch (event->key())
    {
        // 下移
        case Qt::Key_Down:
            moveBy(0, 20);
            if (isColliding())
            {
                moveBy(0, -20);
                // 将小方块从方块组中移除到场景中
                clearBoxGroup();
                // 需要显示新的方块
                emit needNewBox();
            }
            break;
        // 左移
        case Qt::Key_Left:
            moveBy(-20, 0);
            if (isColliding())
                moveBy(20, 0);
            break;
        // 右移
        case Qt::Key_Right:
            moveBy(20, 0);
            if (isColliding())
                moveBy(-20, 0);
            break;
        // 旋转
        case Qt::Key_Up:
            // 在 Qt5 中，QGraphicsItem::rotate 已经不再使用，而是使用 setRotation
            /* old code */
            //    rotate(90);
            //   if (isColliding())
            //       rotate(-90);
            //    break;
            /* old code */

            oldRotate = rotation();
            if (oldRotate >= 360)
            {
                oldRotate = 0;
            }
            setRotation(oldRotate + 90);
            if (isColliding())
            {
                setRotation(oldRotate - 90);
            }
            break;

        // 空格键实现坠落
        case Qt::Key_Space:
            moveBy(0, 20);
            while (!isColliding())
            {
                moveBy(0, 20);
            }
            moveBy(0, -20);
            clearBoxGroup();
            emit needNewBox();
            break;
    }
}

BoxGroup::BoxGroup()
{
    setFlags(QGraphicsItem::ItemIsFocusable);

    // 保存变换矩阵，当 BoxGroup 进行旋转后，可以使用它来进行恢复
    oldTransform = transform();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveOneStep()));
    currentShape = RandomShape;
}

QRectF BoxGroup::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-40 - penWidth / 2, -40 - penWidth / 2, 80 + penWidth, 80 + penWidth);
}

// 碰撞检测
bool BoxGroup::isColliding()
{
    QList<QGraphicsItem*> itemList = childItems();
    QGraphicsItem* item;
    // 使用方块组中的每一个小方块来进行判断
    foreach (item, itemList)
    {
        if (item->collidingItems().count() > 1)
            return true;
    }
    return false;
}

// 创建方块
void BoxGroup::createBox(const QPointF& point, BoxShape shape)
{
    static const QColor colorTable[7] = {QColor(200, 0, 0, 100),    QColor(255, 200, 0, 100), QColor(0, 0, 200, 100),
                                         QColor(0, 200, 0, 100),    QColor(0, 200, 255, 100), QColor(200, 0, 255, 100),
                                         QColor(150, 100, 100, 100)};
    int shapeID = shape;
    if (shape == RandomShape)
    {
        // 产生 0-6 之间的随机数
        shapeID = qrand() % 7;
    }
    // 按照给定的方块形状获取一个颜色
    QColor color = colorTable[shapeID];
    QList<OneBox*> list;
    // 恢复方块组的变换矩阵
    setTransform(oldTransform);
    for (int i = 0; i < 4; i++)
    {
        OneBox* temp = new OneBox(color);
        list << temp;
        addToGroup(temp);
    }
    switch (shapeID)
    {
        case IShape:
            currentShape = IShape;
            list.at(0)->setPos(-30, -10);
            list.at(1)->setPos(-10, -10);
            list.at(2)->setPos(10, -10);
            list.at(3)->setPos(30, -10);
            break;

        case JShape:
            currentShape = JShape;
            list.at(0)->setPos(10, -10);
            list.at(1)->setPos(10, 10);
            list.at(2)->setPos(-10, 30);
            list.at(3)->setPos(10, 30);
            break;

        case LShape:
            currentShape = LShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(-10, 10);
            list.at(2)->setPos(-10, 30);
            list.at(3)->setPos(10, 30);
            break;

        case OShape:
            currentShape = OShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(-10, 10);
            list.at(3)->setPos(10, 10);
            break;

        case SShape:
            currentShape = SShape;
            list.at(0)->setPos(10, -10);
            list.at(1)->setPos(30, -10);
            list.at(2)->setPos(-10, 10);
            list.at(3)->setPos(10, 10);
            break;

        case TShape:
            currentShape = TShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(30, -10);
            list.at(3)->setPos(10, 10);
            break;

        case ZShape:
            currentShape = ZShape;
            list.at(0)->setPos(-10, -10);
            list.at(1)->setPos(10, -10);
            list.at(2)->setPos(10, 10);
            list.at(3)->setPos(30, 10);
            break;

        default: break;
    }
    // 设置位置
    setPos(point);
    // 如果开始就发生碰撞，说明已经结束游戏
    if (isColliding())
    {
        stopTimer();
        emit gameFinished();
    }
}

// 删除方块组中的所有小方块
void BoxGroup::clearBoxGroup(bool destroyBox)
{
    QList<QGraphicsItem*> itemList = childItems();
    QGraphicsItem* item;
    foreach (item, itemList)
    {
        removeFromGroup(item);
        if (destroyBox)
        {
            OneBox* box = (OneBox*)item;
            box->deleteLater();
        }
    }
}

// 向下移动一步
void BoxGroup::moveOneStep()
{
    moveBy(0, 20);
    if (isColliding())
    {
        moveBy(0, -20);
        // 将小方块从方块组中移除到场景中
        clearBoxGroup();
        emit needNewBox();
    }
}

// 开启定时器
void BoxGroup::startTimer(int interval) { timer->start(interval); }

// 停止定时器
void BoxGroup::stopTimer() { timer->stop(); }
