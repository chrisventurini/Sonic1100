#pragma once

#include "Python/PythonProcessor.h"

#include <memory>
#include <QtCore/QtCore>

class WebManager : public QObject
{
	Q_OBJECT

public:
	WebManager(std::unique_ptr<PythonProcessor> pyProcessor = nullptr);

public Q_SLOTS:
	QString play(const QString& pyCode);
	void stop(const QString& sessionId);
	void setVariable(const QString& value);

private:
	std::unique_ptr<PythonProcessor> pyProcessor_;
};
