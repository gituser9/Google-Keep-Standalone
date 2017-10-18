#include "webpage.h"


WebPage::WebPage(QObject *parent) : QWebEnginePage(parent)
{
    isLoaded = false;
}

bool WebPage::acceptNavigationRequest(const QUrl &url, QWebEnginePage::NavigationType type, bool isMainFrame)
{
    Q_UNUSED(isMainFrame)

    if (type == QWebEnginePage::NavigationTypeLinkClicked && isLoaded) {
        //QDesktopServices::openUrl(url);
        return false;
    }
    return true;
}

void WebPage::setIsLoaded(bool isLoaded)
{
    this->isLoaded = isLoaded;
}
