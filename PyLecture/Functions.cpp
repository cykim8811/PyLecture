#include "Functions.h"
#include "Window.h"
#include <iostream>

using namespace std;

static WindowObject* global_window;

PyObject* PyLecture_Init(PyObject* self, PyObject* args) {
    int type;
    if (!PyArg_ParseTuple(args, "i", &type)) {
        return NULL;
    }

    if (type < 0) {
        PyErr_SetString(PyExc_ValueError, "Invalid initialize type");
        return NULL;
    }

    PyObject* arg = Py_BuildValue("(i)", type);
    PyObject* module_window = PyObject_CallObject((PyObject*)&WindowType, arg);
    Py_DECREF(arg);
    PyModule_AddObject(self, "window", module_window);

    global_window = (WindowObject*)module_window;

    Py_RETURN_NONE;
}

PyObject* PyLecture_on(PyObject* self, PyObject* args) {
    int x, y;
    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }
    vector<int> arg = { x, y };
    // cout << global_window->engine->Command("on", arg) << endl;
    call_list.push_back(call{ 0, {x, y} });

    Py_RETURN_NONE;
}

PyObject* PyLecture_off(PyObject* self, PyObject* args) {
    int x, y;
    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }
    vector<int> arg = { x, y };
    // cout << global_window->engine->Command("off", arg) << endl;
    call_list.push_back(call{ 1, {x, y} });

    Py_RETURN_NONE;
}