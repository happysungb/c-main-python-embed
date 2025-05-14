// main_launcher.c
#include <Python.h>

int main(int argc, char *argv[]) {
    // 1. Python 인터프리터 초기화
    Py_Initialize();

    // 2. logic.py 모듈 import
    PyObject *pName = PyUnicode_DecodeFSDefault("logic");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // 3. hello() 함수 실행
        PyObject *pFuncHello = PyObject_GetAttrString(pModule, "hello");
        if (pFuncHello && PyCallable_Check(pFuncHello)) {
            PyObject_CallObject(pFuncHello, NULL);
        }

        // 4. calculate(3, 5) 함수 실행
        PyObject *pFuncCalc = PyObject_GetAttrString(pModule, "calculate");
        if (pFuncCalc && PyCallable_Check(pFuncCalc)) {
            PyObject *args = PyTuple_Pack(2, PyLong_FromLong(3), PyLong_FromLong(5));
            PyObject_CallObject(pFuncCalc, args);
            Py_DECREF(args);
        }

        Py_XDECREF(pFuncHello);
        Py_XDECREF(pFuncCalc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        fprintf(stderr, "⚠️ Failed to load \"logic\"\n");
    }

    // 5. 인터프리터 종료
    Py_Finalize();
    return 0;
}
