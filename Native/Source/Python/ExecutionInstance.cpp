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

void ExecutionInstance::Play(const std::string& pyCode)
{
	thread_ = std::make_unique<std::thread>([&]()
	{
		do
		{
			const PyGILState_STATE gilState = PyGILState_Ensure();

			PyRun_SimpleString(pyCode.c_str());

			PyGILState_Release(gilState);

		} while (repeat_);
	});
}

void ExecutionInstance::Stop()
{
	repeat_ = false;
}
