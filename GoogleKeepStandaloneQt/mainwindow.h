#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

#include "webpage.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *object, QEvent *event) override;

private:
    Ui::MainWindow *ui;
    QWebEngineView *view;
    WebPage *page;

private slots:
    void loadKeepsFinished(bool success);
    void loadKeepsProgress(int progress);

};

#endif // MAINWINDOW_H
