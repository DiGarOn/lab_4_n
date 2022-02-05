//
//  func.h
//  lab_Zoo_class
//
//  Created by Dmitriy Garkin on 30.11.2021.
//

#ifndef func_h
#define func_h

#include <fstream>
#include <iostream>
#include "Zoo.h"

std::ofstream& Open_file_out();
std::ifstream& Open_file_in();

using std::string;
using std::ofstream;
using std::cout;

//функция, записывающая время в нужном нам формате
void Print_time(int time, ofstream &out);
void Print_time(int time);
//функция, позволяющая сравнивать 2 переменные типа zoo для сортировки
bool Is_better(Zoo first, Zoo sec);

//сортировка по возрастанию
void Sort_all_data(Zoo * all_data, int count_zoos);

//функция, записывающая в массив res только те зоопарки, которые
//находятся в стране Х
void In_country(Zoo * all_data, Zoo * res, int count_zoos, int & country_count, string x);

#endif /* func_h */
