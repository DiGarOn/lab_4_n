//
//  func.cpp
//  lab_Zoo_class
//
//  Created by Dmitriy Garkin on 30.11.2021.
//

#include <stdio.h>
#include <fstream>

#include "func.h"

std::ofstream& Open_file_out() {
    std::ofstream* out_p = new std::ofstream;
    std::ofstream&out=*out_p;
    out.open("/Users/dmitriygarkin/Desktop/яп_лаб_2/задача 2/fout2.txt");
    if(!(out.is_open())) {
        std::cout << "file not find\n";
        exit(0);
    }
    return out;
}

std::ifstream& Open_file_in() {
    std::ifstream* in_p = new std::ifstream;
    std::ifstream&in=*in_p;
    in.open("/Users/dmitriygarkin/Desktop/яп_лаб_2/задача 2/fin2.txt");
    if(!(in.is_open())) {
        std::cout << "file not find\n";
        exit(0);
    }
    return in;
}

void Print_time(int time, ofstream &out) {
    if(time < 10) {
        out <<  "0" << time;
    } else {
        out << time;
    }
}
void Print_time(int time) {
    if(time < 10) {
        cout <<  "0" << time;
    } else {
        cout << time;
    }
}

bool Is_better(Zoo first, Zoo sec) {
    double coef_f, coef_s;
    int first_cost = first.Get_cost();
    int first_count = first.Get_count();
    int sec_cost = sec.Get_cost();
    int sec_count = sec.Get_count();
    coef_f = first_cost/first_count;
    coef_s = sec_cost/sec_count;
    return coef_f >= coef_s;
}

void Sort_all_data(Zoo * all_data, int count_zoos) {
    for(int i = 0; i < count_zoos; i++) {
        for(int j = i; j < count_zoos - 1; j++) {
            if(not(Is_better(all_data[i], all_data[j]))) {
                Zoo val =  all_data[i];
                all_data[i] = all_data[j];
                all_data[j] = val;
            }
        }
    }
}

void In_country(Zoo * all_data, Zoo * res, int count_zoos, int & country_count, string x) {
    for(int i = 0; i < count_zoos; i++) {
        string all_data_country = all_data[i].Get_country();
        if(all_data_country == x) {
            res[country_count] = all_data[i];
            country_count ++;         }
    }
}
