#include <qapplication.h>
#include <qwebchannel.h>
#include <qwebengineview.h>
#include <qtwebengineglobal.h>
#include <QWebEngineView>

#include "WebManager.h"

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication app(argc, argv);

	QWebChannel webChannel;
	WebManager webManager;
	webChannel.registerObject("manager", &webManager);

	QWebEngineView webView;
	webView.setUrl(QUrl(QStringLiteral("qrc:/WebUi/index.html")));
	webView.page()->setWebChannel(&webChannel);
	webView.show();

	return app.exec();
}