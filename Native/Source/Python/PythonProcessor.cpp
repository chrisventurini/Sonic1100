#include "PythonProcessor.h"
#include <memory>
#include "../Utils/generateId.h"

using std::string;

PythonProcessor::PythonProcessor()
{
	Py_Initialize();
	PyEval_InitThreads();

	mainModule_ = PyImport_AddModule("__main__");
	globals_ = PyModule_GetDict(mainModule_);
	mainThreadState_ = PyEval_SaveThread();
}

PythonProcessor::~PythonProcessor()
{
	for (auto& instance : executionInstances_)
	{
		instance.second->Stop();
	}

	PyEval_ReleaseLock();
	Py_DECREF(globals_);
	Py_DECREF(mainModule_);
	Py_FinalizeEx();
}

std::string PythonProcessor::Run(const string& pyCode, const bool repeat)
{
	const string sessionId = Utils::generateId();

	executionInstances_[sessionId] = std::make_unique<ExecutionInstance>(sessionId, pyCode, repeat);
	
	executionInstances_[sessionId].get()->Run();

	return sessionId;
}

void PythonProcessor::Stop(const string& sessionId)
{
	executionInstances_[sessionId].get()->Stop();
}

void PythonProcessor::SetValue(const std::string& value) 
{
	PyGILState_STATE gilState = PyGILState_Ensure();

	PyObject* pyValue = Py_BuildValue("s", value.c_str());
	PyDict_SetItemString(globals_, "Foo", pyValue);
	
	PyRun_SimpleString("import threading");
	PyRun_SimpleString("print(threading.get_ident())");

	PyGILState_Release(gilState);
}