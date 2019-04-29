#include "PythonProcessor.h"

#include <thread>

PythonProcessor::PythonProcessor()
{
	Py_Initialize();
	PyEval_InitThreads();

	mainModule_ = PyImport_AddModule("__main__");
	globals_ = PyModule_GetDict(mainModule_);
	threadState_ = PyEval_SaveThread();
}

PythonProcessor::~PythonProcessor()
{
	if (executionThread_ != nullptr)
	{
		executionThread_->join();
	}

	PyEval_RestoreThread(threadState_);
	Py_DECREF(globals_);
	Py_DECREF(mainModule_);
	Py_FinalizeEx();
}

void PythonProcessor::Process(std::string pyCode)
{
	if (executionThread_ != nullptr) { return; }

	executionThread_ = std::make_unique<std::thread>([=]()
	{
		PyGILState_STATE gilState = PyGILState_Ensure();

		PyRun_SimpleString(pyCode.c_str());

		PyGILState_Release(gilState);
	});
}

void PythonProcessor::SetValue(std::string value) 
{
	PyGILState_STATE gilState = PyGILState_Ensure();

	PyObject* pyValue = Py_BuildValue("s", value.c_str());
	PyDict_SetItemString(globals_, "Foo", pyValue);
	
	PyGILState_Release(gilState);
}