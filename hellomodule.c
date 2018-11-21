// 20181121
// Yuqiong Li
// Just to understand how to wrap c code into Python
// https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C

#include<Python.h>

static PyObject* say_hello(PyObject * self, PyObject * args){
    const char * name;

    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;

    printf("Hello %s!\n",name);

    Py_RETURN_NONE;
}

static PyMethodDef HelloMethods[] =
{
    {"say hello", say_hello, METH_VARARGS, "Greet Somebody."},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
inithello(void){
    (void) Py_InitModule("hello", HelloMethods);
}


