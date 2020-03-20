#pragma once
#include <Python.h>
#include "SDL.h"
#include "structmember.h"

typedef struct WindowObject :PyObject {
    PyObject_HEAD
    SDL_Window* window;
    SDL_Renderer* renderer;

    Uint32 prevTime;
    Uint32 currTime;
};

static PyMemberDef WindowMembers[] = {
    {NULL}  /* Sentinel */
};

static PyMethodDef WindowMethods[] = {
    /*{"name", (PyCFunction)Custom_name, METH_NOARGS,
     "Return the name, combining the first and last name"
    },*/
    {NULL}  /* Sentinel */
};

extern PyTypeObject WindowType;
