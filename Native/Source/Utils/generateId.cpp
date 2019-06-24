#include "generateId.h"

#include <QUuid>

namespace Utils
{
	std::string generateId()
	{
		return QUuid::createUuid()
						.toString(QUuid::WithoutBraces)
						.toStdString();
	}
}