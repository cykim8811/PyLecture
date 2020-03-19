#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(PyLecture_example_doc, "example(obj, number)\
\
Example function");

PyObject *PyLecture_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to PyLecture in exec_PyLecture().
 */
static PyMethodDef PyLecture_functions[] = {
    { "example", (PyCFunction)PyLecture_example, METH_VARARGS | METH_KEYWORDS, PyLecture_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize PyLecture. May be called multiple times, so avoid
 * using static state.
 */
int exec_PyLecture(PyObject *module) {
    PyModule_AddFunctions(module, PyLecture_functions);

    PyModule_AddStringConstant(module, "__author__", "cykim");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2020);

    return 0; /* success */
}

/*
 * Documentation for PyLecture.
 */
PyDoc_STRVAR(PyLecture_doc, "The PyLecture module");


static PyModuleDef_Slot PyLecture_slots[] = {
    { Py_mod_exec, exec_PyLecture },
    { 0, NULL }
};

static PyModuleDef PyLecture_def = {
    PyModuleDef_HEAD_INIT,
    "PyLecture",
    PyLecture_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    PyLecture_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_PyLecture() {
    return PyModuleDef_Init(&PyLecture_def);
}
