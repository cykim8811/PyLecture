#include "Window.h"
#include <iostream>

using namespace std;

void WindowDealloc(WindowObject* self) {
    SDL_DestroyRenderer(self->renderer);
    SDL_DestroyWindow(self->window);
    delete self->engine;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* WindowNew(PyTypeObject* type, PyObject* args) {
    WindowObject* self;
    self = (WindowObject*)type->tp_alloc(type, 0);

    if (self != NULL) {

    }
    return (PyObject*)self;
}

static int run_tick(void *arg) {
    WindowObject* self = (WindowObject*)arg;

    int last_command = 0;

    self->window = SDL_CreateWindow(
        self->engine->get_name(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        self->engine->get_width(),
        self->engine->get_height(),
        0
    );
    self->renderer = SDL_CreateRenderer(self->window, -1, SDL_RENDERER_ACCELERATED);

    self->prevTime = SDL_GetTicks();
    self->currTime = 0;

    while (true) {
        self->currTime = SDL_GetTicks();
        float dT = float(self->currTime - self->prevTime) / 1000;
        self->prevTime = self->currTime;

        self->engine->Tick(dT);
        SDL_SetRenderDrawColor(self->renderer, 255, 255, 255, 255);
        SDL_RenderClear(self->renderer);
        self->engine->Draw(self->renderer);
        SDL_RenderPresent(self->renderer);

        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (self->engine->Event(ev) < 0) {
                return 0;
            }
        }
        while (call_list.size() > last_command) {
            call c = call_list[last_command];
            self->engine->Command(c.cmd, c.params);
            last_command++;
        }
        SDL_Delay(100);
        //std::this_thread::sleep_for(0.1s);
    }
}


static int WindowInit(WindowObject* self, PyObject* args, PyObject* kwds) {
    static char* kwlist[] = { "type", NULL };
    int t = 0;
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "i", kwlist, &t)) {
        return NULL;
    }

    /*
     *  Assign Engine for each type int
     */
    switch (t) {
    case 0:
        self->engine = new GridEngine();
        break;
    default:
        break;
    }
    /* TODO: add thread to call engine's ftns */
    self->thr = SDL_CreateThread(run_tick, "WindowThread", (void*)self);

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
    (newfunc) WindowNew,              /* tp_new */
    0,                              /* tp_free */
    0,                              /* tp_is_gc */
};

vector<call> call_list;