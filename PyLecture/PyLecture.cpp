#include <Python.h>
#include "SDL.h"
#include "Functions.h"

#include "Window.h"


int exec_PyLecture(PyObject *module) {

    return 0; /* success */
}

PyDoc_STRVAR(PyLecture_doc, "The PyLecture module");


static PyModuleDef PyLecture_def = {
    PyModuleDef_HEAD_INIT,
    "PyLecture",
    PyLecture_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    NULL,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_PyLecture() {
    PyObject* module;

    module = PyModule_Create(&PyLecture_def);
    if (module == NULL) return NULL;

    PyModule_AddFunctions(module, PyLecture_functions);


    if (PyType_Ready(&WindowType) < 0) return NULL;
    Py_INCREF(&WindowType);
    if (PyModule_AddObject(module, "Window", (PyObject*)&WindowType) < 0) {
        Py_DECREF(&WindowType);
        Py_DECREF(module);
        return NULL;
    }
    PyModule_AddStringConstant(module, "__author__", "cykim");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2020);

    SDL_Init(SDL_INIT_EVERYTHING);
    PyObject * module_window = PyObject_CallObject((PyObject*)&WindowType, NULL);
    PyModule_AddObject(module, "window", module_window);

    return module;
}
