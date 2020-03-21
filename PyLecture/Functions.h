#pragma once
#include <Python.h>
#include "Window.h"

PyObject* PyLecture_Init(PyObject* self, PyObject* args);
PyDoc_STRVAR(PyLecture_example_doc, "PyLecture_Init(type)\
\
Initialize PyLecture");

PyObject* PyLecture_on(PyObject* self, PyObject* args);
PyDoc_STRVAR(PyLecture_on_doc, "PyLecture_Init(type)\
\
Initialize PyLecture");

static PyMethodDef PyLecture_functions[] = {
	{ "PyLecture_Init", (PyCFunction)PyLecture_Init, METH_VARARGS, PyLecture_example_doc },
	{ "on", (PyCFunction)PyLecture_on, METH_VARARGS, PyLecture_on_doc },
	{ NULL, NULL, 0, NULL } /* marks end of array */
};

extern WindowObject* global_window;