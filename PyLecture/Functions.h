#pragma once
#include <Python.h>

PyDoc_STRVAR(PyLecture_example_doc, "example(obj, number)\
\
Example function");

PyObject* PyLecture_example(PyObject* self, PyObject* args, PyObject* kwargs);

static PyMethodDef PyLecture_functions[] = {
	{ "example", (PyCFunction)PyLecture_example, METH_VARARGS | METH_KEYWORDS, PyLecture_example_doc },
	{ NULL, NULL, 0, NULL } /* marks end of array */
};