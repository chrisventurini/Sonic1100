#include "ExecutionInstance.h"

#include <memory>
#include <thread>
#include <string>
#include <unordered_map>
#pragma once

#include <utility>
#include <Python.h>


class PythonProcessor
{
public:
	PythonProcessor();
	~PythonProcessor();

	std::string CreateSession();
	std::string Run(const std::string& pythonCode, const bool repeat);
	void Stop(const std::string& sessionId);
	void SetValue(const std::string& value);

private:
	PyObject* mainModule_ = nullptr;
	PyObject* globals_ = nullptr;
	PyThreadState* mainThreadState_ = nullptr;
	std::unordered_map<std::string, std::unique_ptr<ExecutionInstance>> executionInstances_;
};