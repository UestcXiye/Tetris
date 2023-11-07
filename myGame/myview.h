#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <phonon>

class BoxGroup;

class MyView : public QGraphicsView
{
    Q_OBJECT
private:
    BoxGroup* boxGroup;
    BoxGroup* nextBoxGroup;
    QGraphicsLineItem* topLine;
    QGraphicsLineItem* bottomLine;
    QGraphicsLineItem* leftLine;
    QGraphicsLineItem* rightLine;
    qreal gameSpeed;
    QList<int> rows;
    QGraphicsTextItem* gameScoreText;
    QGraphicsTextItem* gameLevelText;
    QGraphicsWidget* maskWidget;  // 遮罩面板
    // 各种按钮
    QGraphicsWidget* startButton;
    QGraphicsWidget* finishButton;
    QGraphicsWidget* restartButton;
    QGraphicsWidget* pauseButton;
    QGraphicsWidget* optionButton;
    QGraphicsWidget* returnButton;
    QGraphicsWidget* helpButton;
    QGraphicsWidget* exitButton;
    QGraphicsWidget* showMenuButton;
    // 各种文本
    QGraphicsTextItem* gameWelcomeText;
    QGraphicsTextItem* gamePausedText;
    QGraphicsTextItem* gameOverText;
    // 音乐部件
    Phonon::MediaObject *backgroundMusic;
    Phonon::MediaObject *clearRowSound;

    void initView();
    void initGame();
    void updateScore(const int fullRowNum = 0);

protected:
    void keyPressEvent(QKeyEvent* event);

public:
    explicit MyView(QWidget* parent = 0);

public slots:
    void startGame();
    void clearFullRows();
    void moveBox();
    void gameOver();
    void restartGame();
    void finishGame();
    void pauseGame();
    void returnGame();
    void aboutToFinish();
};

#endif  // MYVIEW_H
