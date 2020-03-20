#include "Window.h"
#include <iostream>

using namespace std;

void WindowDealloc(WindowObject* self) {
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* WindowNew(PyTypeObject* type, PyObject* args, PyObject* kwds) {
    WindowObject* self;
    self = (WindowObject*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->window = SDL_CreateWindow(
            "PyTetris",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            32 * 22, 32 * 22, 0
        );
        self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);

        self->prevTime = SDL_GetTicks();
        self->currTime = 0;
    }
    return (PyObject*)self;
}


static int WindowInit(WindowObject* self, PyObject* args, PyObject* kwds) {
    static char* kwlist[] = { NULL };
    //if (!PyArg_ParseTupleAndKeywords(args, kwds, "", kwlist))
    //    return -1;

    return 0;
}

PyTypeObject WindowType{
    PyVarObject_HEAD_INIT(NULL, 0)
    "PyLecture.Window",             /* tp_name */
    sizeof(WindowObject),           /* tp_basicsize */
    0,                              /* tp_itemsize */
    /* methods */
    (destructor)WindowDealloc, /* tp_dealloc */
    0,                              /* tp_print */
    0,                              /* tp_getattr */
    0,                              /* tp_setattr */
    0,                              /* tp_reserved */
    0,                              /* tp_repr */
    0,                              /* tp_as_number */
    0,                              /* tp_as_sequence */
    0,                              /* tp_as_mapping */
    0,                              /* tp_hash */
    0,                              /* tp_call */
    0,                              /* tp_str */
    0,                              /* tp_getattro */
    0,                              /* tp_setattro */
    0,                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    0,                              /* tp_doc */
    0,                              /* tp_traverse */
    0,                              /* tp_clear */
    0,                              /* tp_richcompare */
    0,                              /* tp_weaklistoffset */
    0,                              /* tp_iter */
    0,                              /* tp_iternext */
    WindowMethods,                  /* tp_methods */
    WindowMembers,                  /* tp_members */
    0,                              /* tp_getset */
    0,                              /* tp_base */
    0,                              /* tp_dict */
    0,                              /* tp_descr_get */
    0,                              /* tp_descr_set */
    0,                              /* tp_dictoffset */
    (initproc) WindowInit,/* tp_init */
    0,                              /* tp_alloc */
    WindowNew,              /* tp_new */
    0,                              /* tp_free */
    0,                              /* tp_is_gc */
};

