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
/*
    struct Print_detector
    {
        static auto check(void*) -> void; // раз уж С++11, напишем в постфиксной форме - так красивее и однообразнее :)
        template<typename T>
        static auto check(T* p) -> decltype(p->Print())*; // указатель на чего бы то ни было отличается от не-указателя

        typedef void* match_type; // но мы ожидаем конкретно void Print(), поэтому проверяем на void*
    };

    // менее громоздкий способ писать метафункции - это наследоваться от готовых
    template<typename T> struct has_Print : std::is_same<Print_detector::match_type, decltype(Print_detector::check((T*)nullptr))> {};
*/

    template<typename T> struct has_Print{
    private:  // Спрячем от пользователя детали реализации.
        static int detect(...);  // Статическую функцию и вызывать проще.
        template<typename U> static decltype(std::declval<U>().Print()) detect(const U&);
    public:
        static constexpr bool value = std::is_same<void, decltype(detect(std::declval<T>()))>::value;  // Вот видите, готово.
    };

/*
    template <typename T> 
    auto Print(const T&q)->decltype( std::declval<std::ostream&> <<q,str() ){
        stringstream ss; 
        ss<<q; 
        return q. str();
    }
    template <typename T> 
    auto Print(const T&q)->decltype( q. Print() ){
        return q. Print();
    }
*/

    //а тут мы надеемся, что пользователь не дурак и реализовал перегрузку оператора вывода в своем классе)
    //в противном случае вылезет ошибка    
    friend std::ostream & operator << (std::ostream & out, MyDeck & deck) {
        for(int i = 0; i < deck._size; i++) {
            out << deck._data[i] << endl;
        }
        return out;
    }
    

};



#endif 