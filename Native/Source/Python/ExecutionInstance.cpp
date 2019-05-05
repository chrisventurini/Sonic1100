#include "ExecutionInstance.h"

#include <Python.h>

ExecutionInstance::ExecutionInstance(std::string instanceId, const std::string pyCode, bool repeat)
	: id_(instanceId), pyCode_(pyCode), run_(repeat)
{
}

ExecutionInstance::~ExecutionInstance()
{
	if (thread_ == nullptr) { return; }

	Stop();

	thread_.get()->join();
}

void ExecutionInstance::Run()
{
	thread_ = std::make_unique<std::thread>([&]()
	{
		do
		{
			const PyGILState_STATE gilState = PyGILState_Ensure();

			PyRun_SimpleString(pyCode_.c_str());

			PyGILState_Release(gilState);

		} while (run_);
	});
}

void ExecutionInstance::Stop()
{
	run_ = false;
}
