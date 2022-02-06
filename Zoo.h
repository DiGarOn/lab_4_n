//
//  Zoo.h
//  lab_Zoo_class
//
//  Created by Dmitriy Garkin on 30.11.2021.
//

#ifndef Zoo_h
#define Zoo_h

#include <string>
#include <iostream>

using std::string;
using std::ofstream;

class Zoo {
private:
    string name;
    string country;
    string * data;
    int count;
    int * time;
    int cost;
public:
    //конструктор без параметров
    Zoo();
    //конструкторс с параметрами
    Zoo(string new_name, string new_coutry, string * new_data,
        int new_count, int * new_time,  int new_cost);
    //конструктор копирования
    Zoo(const Zoo& value);
    //деструктор
    ~Zoo();
    //вывод всех данных о переменной типа Zoo
    void Print(std::ofstream &out) const;
    void Print() const;
    //геттеры. нужны, тк все переменные лежат в private
    string Get_name() const;

    string Get_country() const;

    int Get_count() const;

    string * Get_data() const;

    int * Get_time() const;

    int Get_cost() const;

    //выводы каждой переменной
    void Print_name(ofstream& out) const;
    void Print_name() const;
    void Print_country(ofstream &out) const;
    void Print_country() const;
    void Print_count(ofstream &out) const;
    void Print_count() const;
    void Print_data(ofstream &out) const;
    void Print_data() const;
    void Print_time(ofstream &out) const;
    void Print_time() const;
    void Print_cost(ofstream& out) const;
    void Print_cost() const;

    //изменение каждой переменной
    void Change_name(string new_name);

    void Change_country(string new_country);

    void Change_data(string* new_data, int new_count);

    void Change_time(int * new_time);

    void Change_cost(int new_cost);

    //функция, считающая, сколько животных можно обойти за время работы
    //зоопарка, если тратить на каждого n минут
    int How_much(int n);

    friend std::ostream& operator << (std::ostream &out, const Zoo & zoo) {
        out << "name: " << zoo.name << "country: " << zoo.country << std::endl;
        return out;
    }
};


#endif /* Zoo_h */
