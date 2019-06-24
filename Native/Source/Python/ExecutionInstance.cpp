#include "ExecutionInstance.h"

#include <Python.h>

#include "../Utils/generateId.h"

ExecutionInstance::ExecutionInstance()
	: id_(Utils::generateId())
{
}

ExecutionInstance::~ExecutionInstance()
{
	if (thread_ == nullptr) { return; }

	Stop();

	thread_.get()->join();
}

std::string ExecutionInstance::GetId() const
{
	return id_;
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
