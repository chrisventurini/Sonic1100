#include "WebManager.h"

#include "Python\PythonProcessor.h"

WebManager::WebManager(std::unique_ptr<PythonProcessor> pyProcessor)
{
	if (pyProcessor == nullptr)
	{
		pyProcessor_ = std::make_unique<PythonProcessor>();
	}
}

QString WebManager::play(const QString& pyCode)
{
	std::string codeInstanceId = pyProcessor_.get()->Run(pyCode.toStdString(), true);

	return QString::fromStdString(codeInstanceId);
}

void WebManager::stop(const QString& sessionId)
{
	pyProcessor_.get()->Stop(sessionId.toStdString());
}

void WebManager::setVariable(const QString& value)
{
	pyProcessor_.get()->SetValue(value.toStdString());
}

