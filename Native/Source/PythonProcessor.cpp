#include "PythonProcessor.h"

#include <thread>

PythonProcessor::PythonProcessor()
{
	Py_Initialize();

	mainModule_ = PyImport_AddModule("__main__");
	globals_ = PyModule_GetDict(mainModule_);
}

PythonProcessor::~PythonProcessor()
{
	Py_FinalizeEx();
}

void PythonProcessor::Process(std::string pyCode)
{
	PyRun_SimpleString(pyCode.c_str());
}

void PythonProcessor::SetValue(std::string value) 
{
	PyObject* pyValue = Py_BuildValue("s", value.c_str());
	PyDict_SetItemString(globals_, "Foo", pyValue);
}