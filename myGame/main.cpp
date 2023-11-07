#include <QApplication>
#include <QSplashScreen>
#include <QTextCodec>
#include <QTime>

#include "myview.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 解决 Qt 中文乱码问题
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    // 设置随机数的初始值
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QPixmap pix(":/images/logo.png");
    QSplashScreen splash(pix);
    splash.resize(pix.size());
    splash.show();
    app.processEvents();

    MyView view;
    view.show();

    splash.finish(&view);

    return app.exec();
}
