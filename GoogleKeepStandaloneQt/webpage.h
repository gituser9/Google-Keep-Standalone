#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QObject>
#include <QWebEnginePage>
#include <QDesktopServices>


class WebPage : public QWebEnginePage
{
    Q_OBJECT

public:
    WebPage(QObject *parent = 0);

    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame) override;
    void setIsLoaded(bool isLoaded);

private:
    bool isLoaded;

};

#endif // WEBPAGE_H
