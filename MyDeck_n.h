#ifndef MYDECK_H
#define MYDECK_H

#include "Zoo.h"
#include <utility>

using std::cout;
using std::endl;
using std::ostream;

template<typename t>
class MyDeck{
    t *_data;
    int _size;
    int _top;
    int max_size;
public:
    int size() { return _size; }

    void push_back(t item) {
        if(_size + 1 > max_size) {
            cout << "deck if full" << endl;
            return;
        }
        t *new_data = new t[_size + 1];
        for(int i = 0; i < _size; i++) {
            new_data[i] = _data[i];
        }
        new_data[_size] = item;
        //cout << new_data[_size] << " " << _size << endl;
        delete[]_data;
        _size++;
        _data = new_data;
        /*
        cout << "__________________" << endl;
        for(int i = 0; i < _size; i++) {
            cout << _data[i] << " ";
        }
        cout << "__________________" << endl;
        */
    }

    void push_front(t item) {
        if(_size + 1 > max_size) {
            cout << "deck if full" << endl;
            return;
        }
        //cout << "push_front: " << endl;
        t *new_data = new t[_size + 1];
        //cout << item << " ";
        for(int i = 0; i < _size; i++) {
            new_data[i+1] = _data[i];
            //cout << new_data[i+1] << " ";
        }
        //cout << endl;
        new_data[0] = item;
        delete[]_data;
        _size++;
        _data = new_data;
    }

    t pop_back() {
        //cout << "pop_back: " << endl;
        if(_size == 0) {
            cout << "deck empty" << endl;
            exit(0);
        }
        t *new_data = new t[_size - 1];
        t val = _data[_size-1];
        for(int i = 0; i < _size-1; i++) {
            new_data[i] = _data[i];
            //cout << new_data[i] << " ";
        }
        //cout << endl;
        delete[]_data;
        _data = new_data;
        _size--;
        return val;
    }

    t pop_front() {
        //cout << "pop_front: " << endl;
        if(_size == 0) {
            cout << "deck emoty" << endl;
            exit(0);
        }
        t *new_data = new t[_size - 1];
        t val = _data[0];
        for(int i = 0; i < _size-1; i++) {
            new_data[i] = _data[i+1];
            //cout << new_data[i] << " ";
        }
        //cout << endl;
        delete[]_data;
        _data = new_data;
        
        _size--;
        //cout << "size: " << _size << endl;
        return val;
    }

    MyDeck(int new_max_size) {
        max_size = new_max_size;
        _size = 0;
        _data = new t[0];
        
    }
    MyDeck(const MyDeck &new_deck) {
        max_size = new_deck.max_size;
        _data = new t[new_deck._size];
        assert(_data != nullptr);
        _size = new_deck._size;
        for(int i = 0; i < _size; i++) {
            _data[i] = new_deck._data[i];
        }
    }
    ~MyDeck() {
        if(_data != nullptr) {
            delete[] _data;
            _data = nullptr;
        }
    }

    MyDeck & operator = (const MyDeck & deck) {
        if(this == &deck) { //проверка на самокопирование
            return *this;
        }
        if(_data != nullptr) { //чистим все данные для перезаписи
            delete[] _data;
        }

        _data = new t[deck._size];
        assert(_data != nullptr);

        _size = deck._size;
        for(int i = 0; i < _size; i++) {
            _data[i] = deck._data[i];
        }
        return *this;
    }

    friend bool operator == (const MyDeck &first, const MyDeck &second) {
        if(first._size == second._size && first._top == second._top) return 1;
            
        return 0;
    }
    template <typename Y>
    auto Print_value(const Y&q)->decltype(q.Print(),0){
        q.Print();
        return 0;
    }

    template <typename Y>
    auto Print_value(const Y&q)->decltype((    *(std::ostream*)(0)     <<q,0)){
        cout<<q << " ";
        return 0;
    }

    void Print() {
        for(int i = 0; i < _size; i++) {
            Print_value( _data[i]);
        } 
        cout << endl;
    }

    friend std::ostream & operator << (std::ostream & out, MyDeck & deck) {
        deck.Print();
        return out;
    }
    

};



#endif 
