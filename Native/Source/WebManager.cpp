#include "WebManager.h"

WebManager::WebManager(std::unique_ptr<PythonProcessor> pyProcessor)
{
	if (pyProcessor == nullptr)
	{
		pyProcessor_ = std::make_unique<PythonProcessor>();
	}
}

void WebManager::executeCode(const QString pyCode)
{
	pyProcessor_.get()->Process(pyCode.toStdString());
}

void WebManager::setVariable(const QString value)
{
	pyProcessor_.get()->SetValue(value.toStdString());
}

