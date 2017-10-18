#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(1024, 750);
    this->setWindowTitle("Google Keep Standalone");
    this->installEventFilter(this);

    // fixme: from form
    ui->progressBar->move((this->width()/2) - (ui->progressBar->width()/2), this->height()/2);

    view = new QWebEngineView(this);
    page = new WebPage(this);
    view->resize(this->width(), this->height());
    view->setPage(page);
    view->load(QUrl("https://keep.google.com"));
    view->hide();

    connect(view, &QWebEngineView::loadFinished, this, &MainWindow::loadKeepsFinished);
    connect(view, &QWebEngineView::loadProgress, this, &MainWindow::loadKeepsProgress);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == this && event->type() == QEvent::Resize) {
        view->resize(this->width(), this->height());
        return true;
    }
    return false;
}


// SLOTS

void MainWindow::loadKeepsFinished(bool success)
{
    if (!success) {
        return;
    }
    page->setIsLoaded(true);
    view->show();
}

void MainWindow::loadKeepsProgress(int progress)
{
    ui->progressBar->setValue(progress);
}
