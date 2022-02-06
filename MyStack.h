#ifndef MYSTACK_H
#define MYSTACK_H

#include "Zoo.h"

/*
using std::cout;
using std::endl;
using std::ostream;
*/

template<typename t>
class MyStack {
    t *_data;
    int _size;
    int _top;
public:
    void push(t item) {
        if(isFool()) {
            cout << "stack is fool" << endl;
            exit(0);
        }
        _data[_top++] = item;
    }
    t pop() {
        if(isEmpty()) {
            cout << "stack is empty" << endl;
            exit(0);
        }
        return _data[_top--];
    }
    
    int size() {
        return _top;
    }
    t top() {
        return _data[_top];
    }
    bool isFool() {
        return _top == _size;
    }
    bool isEmpty() {
        return _top == 0;
    }
    void Print() {
        for(int i = 1; i <= _top; i++) {
            _data[i].Zoo::Print();
        }
    }

    friend ostream& operator << (ostream &out, const MyStack & stack) {
        for(int i = 1; i <= stack._top; i++) {
            stack._data[i].t::Print();
        }
        return out;
    }

    friend bool operator == (const MyStack &first, const MyStack &second) {
        if(first._size == second._size && first._top == second._top) return 1;
            
        return 0;
    }

    MyStack(int max_size = 1) {
        _data = new t[max_size];
        assert(_data != nullptr);
        _size = max_size;
        _top = 0;
    }
    MyStack(const MyStack &new_stack) {
        _data = new t[new_stack._size];
        assert(_data != nullptr);
        _size = new_stack._size;
        for(int i = 0; i < _size; i++) {
            _data[i] = new_stack._data[i];
        }
        _top = new_stack._top;
    }
    ~MyStack() {
        if(_data != nullptr) {
            delete[] _data;
            _data = nullptr;
        }
    }

    MyStack & operator = (const MyStack & stack) {
        if(this == &stack) { //проверка на самокопирование
            return *this;
        }
        if(_data != nullptr) { //чистим все данные для перезаписи
            delete[] _data;
        }

        _data = new t[stack._size];
        assert(_data != nullptr);

        _size = stack._size;
        for(int i = 0; i < _size; i++) {
            _data[i] = stack._data[i];
        }
        _top = stack._top;
        return *this;
    }

};

#endif