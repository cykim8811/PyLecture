#pragma once
#include <Python.h>
#include "Window.h"
#include "call.h"

PyObject* PyLecture_Init(PyObject* self, PyObject* args);
PyDoc_STRVAR(PyLecture_example_doc, "Init(type)\
\
Initialize PyLecture");

PyObject* PyLecture_on(PyObject* self, PyObject* args);
PyDoc_STRVAR(PyLecture_on_doc, "on(x, y)\
\
Turn a grid on");

PyObject* PyLecture_off(PyObject* self, PyObject* args);
PyDoc_STRVAR(PyLecture_off_doc, "off(x, y)\
\
Turn a grid off");

static PyMethodDef PyLecture_functions[] = {
	{ "Init", (PyCFunction)PyLecture_Init, METH_VARARGS, PyLecture_example_doc },
	{ "on", (PyCFunction)PyLecture_on, METH_VARARGS, PyLecture_on_doc },
	{ "off", (PyCFunction)PyLecture_off, METH_VARARGS, PyLecture_off_doc },
	{ NULL, NULL, 0, NULL } /* marks end of array */
};

extern WindowObject* global_window;

