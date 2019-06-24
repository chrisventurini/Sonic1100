#include "WebManager.h"

#include "Python\PythonProcessor.h"

WebManager::WebManager(std::unique_ptr<PythonProcessor> pyProcessor)
{
	if (pyProcessor == nullptr)
	{
		pyProcessor_ = std::make_unique<PythonProcessor>();
	}
}

QString WebManager::createSession()
{
	std::string sessionId = pyProcessor_.get()->CreateSession();

	return QString::fromStdString(sessionId);
}

void WebManager::play(const QString& sessionId, const QString& pyCode)
{
	pyProcessor_.get()->Run(sessionId.toStdString(),pyCode.toStdString(), true);
}

void WebManager::stop(const QString& sessionId)
{
	pyProcessor_.get()->Stop(sessionId.toStdString());
}

void WebManager::setVariable(const QString& value)
{
	pyProcessor_.get()->SetValue(value.toStdString());
}

