#include <stdlib.h>

#include "stack.h"

template <class T>
mystack<T>::mystack() {
    top = 0;
    max_size = 10;
    stk = (T *) malloc(sizeof(T) * max_size);
}

template <class T>
mystack<T>::~mystack() {
    free(stk);
}

template <class T>
size_t mystack<T>::size() {
    return top;
}

template <class T>
T mystack<T>::pop() {
    if (top)
        return stk[top--];
    else
        throw "empty array";
}

template <class T>
void mystack<T>::push(T v) {
    if (top == max_size) {
        max_size *= 2;
        stk = (T *) realloc(stk, sizeof(T) * max_size);
    }
    stk[top++] = v;
}

template class mystack<int>;
