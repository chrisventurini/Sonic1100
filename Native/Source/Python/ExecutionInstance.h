#pragma once

#include <string>
#include <thread>

class ExecutionInstance
{
public:
	ExecutionInstance(); 
	~ExecutionInstance();
	std::string GetId() const;
	void Run();
	void Stop();

private:
	std::string id_;
	std::string pyCode_;
	bool run_ = false;
	std::unique_ptr<std::thread> thread_ = nullptr;
};