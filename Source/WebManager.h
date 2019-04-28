#include <QtCore/QtCore>

class WebManager : public QObject
{
	Q_OBJECT

public slots:
	void jsCallMe();
};