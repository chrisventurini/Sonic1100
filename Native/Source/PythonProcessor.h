#include <memory>
#include <thread>
#include <string>

#include <Python.h>

class PythonProcessor
{
public:
	PythonProcessor();
	~PythonProcessor();

	void Process(std::string pythonCode);
	void SetValue(std::string value);

private:
	PyObject* mainModule_ = nullptr;
	PyObject* globals_ = nullptr;
	PyThreadState* threadState_ = nullptr;

	std::unique_ptr<std::thread> executionThread_ = nullptr;
};