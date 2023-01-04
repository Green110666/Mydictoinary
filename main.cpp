#include<Python.h>
#include<iostream>
//#pragma once(lib,"python39.lib") 
using namespace std;
int main(){
    Py_SetPythonHome(L"D:/Anaconda3");
    Py_Initialize();
    //PyRun_SimpleString("import sys");
    //PyRun_SimpleString("sys.path.append('D:/github/MyDictionary')");
    //加载模组
    PyObject* module=PyImport_ImportModule("spider");
    if (!module) {
        // An error occurred
        cerr << "Failed to import py" <<endl;
        return 1;
    }
    //获取函数
    PyObject* add_func = PyObject_GetAttrString(module, "add");
    if (add_func == NULL || !PyCallable_Check(add_func)) {
        // An error occurred
        return 1;
    }
    //设置参数
    PyObject* args = PyTuple_New(2);
    PyTuple_SetItem(args, 0, PyLong_FromLong(1));
    PyTuple_SetItem(args, 1, PyLong_FromLong(6));
    //调用函数
    PyObject* result = PyObject_CallObject(add_func, args);
    if (result == NULL)
    {
        PyErr_Print();
        return 1;
    }
/****
    if (PyLong_Check(result))
    {
        long value = PyLong_AsLong(result);
        // 处理 value
    }
    else if (PyFloat_Check(result))
    {
        double value = PyFloat_AsDouble(result);
        // 处理 value
    }
    else if (PyUnicode_Check(result))
    {
        PyObject* bytes = PyUnicode_AsEncodedString(result, "utf-8", "strict");
        if (bytes == NULL)
        {
            PyErr_Print();
            return 1;
        }

        char* value = PyBytes_AsString(bytes);
        // 处理 value
    }
***/
    long value = PyLong_AsLong(result);
    cout<<value;
    system("pause");
    return 0;
}