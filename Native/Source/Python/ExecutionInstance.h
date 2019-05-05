#pragma once

#include <string>
#include <thread>

class ExecutionInstance
{
public:
	explicit ExecutionInstance(std::string instanceId, const std::string pyCode, bool repeat); 
	~ExecutionInstance();
	void Run();
	void Stop();

private:
	std::string id_;
	std::string pyCode_;
	bool run_ = false;
	std::unique_ptr<std::thread> thread_ = nullptr;
};