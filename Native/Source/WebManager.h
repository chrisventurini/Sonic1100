#include "PythonProcessor.h"

#include <memory>
#include <QtCore/QtCore>

class WebManager : public QObject
{
	Q_OBJECT

public:
	WebManager(std::unique_ptr<PythonProcessor> pyProcessor = nullptr);

public Q_SLOTS:
	void executeCode(const QString pyCode);
	void setVariable(const QString value);

private:
	std::unique_ptr<PythonProcessor> pyProcessor_;
};