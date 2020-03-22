#pragma once
#include <Python.h>
#include "SDL.h"
#include "structmember.h"
#include <thread>
#include <chrono>
#include "Engine.h"
#include "GridEngine.h"
#include "ArrowEngine.h"
#include "SDL_thread.h"
#include "call.h"

typedef struct WindowObject :PyObject {
    PyObject_HEAD
    SDL_Window* window;
    SDL_Renderer* renderer;

    Uint32 prevTime;
    Uint32 currTime;

    Engine* engine;
    SDL_Thread* thr;
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

extern vector<call> call_list;
