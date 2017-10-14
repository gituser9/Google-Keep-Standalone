#include "mainwindow.h"
#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/google_keep_logo.png"));

    MainWindow w;
    w.show();

//    QWebEngineView view;
//    view.setUrl(QUrl(QStringLiteral("https://keep.google.com")));
//    view.resize(1024, 750);
//    view.show();

    return a.exec();
}
