#include "PythonProcessor.h"
#include <memory>

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

std::string PythonProcessor::CreateSession()
{
	auto executionSession = std::make_unique<ExecutionInstance>();

	string newSessionId = executionSession->GetId();

	executionInstances_.insert({ newSessionId, std::move(executionSession) });

	return newSessionId;
}

void PythonProcessor::Play(const string& sessionId, const string& pyCode, const bool repeat)
{
	executionInstances_[sessionId].get()->Play(pyCode);
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