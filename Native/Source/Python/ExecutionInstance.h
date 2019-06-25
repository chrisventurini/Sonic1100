#pragma once

#include <string>
#include <thread>

class ExecutionInstance
{
public:
	ExecutionInstance(); 
	~ExecutionInstance();
	std::string GetId() const;
	void Play(const std::string& pyCode);
	void Stop();

private:
	std::string id_;
	bool repeat_ = false;
	std::unique_ptr<std::thread> thread_ = nullptr;
};