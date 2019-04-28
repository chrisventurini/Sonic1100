#include <Python.h>
#include <string>

class PythonProcessor
{
public:
	PythonProcessor();
	~PythonProcessor();

	void Process(std::string pythonCode);
	void SetValue(std::string value);

private:
	PyObject* mainModule_;
	PyObject* globals_;
};