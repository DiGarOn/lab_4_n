//
//  Zoo.cpp
//  lab_Zoo_class
//
//  Created by Dmitriy Garkin on 30.11.2021.
//

#include <stdio.h>

#include "func.h"
#include "Zoo.h"

Zoo::Zoo() {
    name = "No name";
    country  = "No contry";
    data = new string[0];
    count = 0;
    time = new int[4];
    time[0] = time[1] = time[2] = time[3] = 0;
    cost = 0;
}

Zoo::Zoo(string new_name, string new_coutry, string * new_data,
    int new_count, int * new_time,  int new_cost) {
    name = new_name;
    country = new_coutry;
    count = new_count;
    if(count < 0) {
        cout << "u can't change count in this way";
        exit(0);
    }
    data = new string[count];
    for(int i = 0; i < count; i++) {
        data[i] = new_data[i];
    }
    time = new int[4];
    for(int i = 0; i < 4; i++) {
        time[i] = new_time[i];
        if(time[i] < 0) {
           cout << "u can't change time in this way";
            exit(0);
        }
        if(i % 2 == 0){
            if(time[i] > 23) {
                cout << "u can't change time in this way";
                exit(0);
            }
        } else {
            if(time[i] > 59) {
                cout << "u can't change time in this way";
                exit(0);
            }
        }
    }
    cost = new_cost;
}

Zoo::Zoo(const Zoo& value) {
    name = value.name;
    country = value.country;
    count = value.count;
    data = new string[count];
    for(int i = 0; i < count; i++) {
        data[i] = value.data[i];
    }
    time = new int[4];
    for(int i = 0; i < 4; i++) {
        time[i] = value.time[i];
    }
    cost = value.cost;
}

Zoo::~Zoo() {
    delete[] data;
    delete[] time;
}

void Zoo::Print(ofstream &out) const {
    out << "Name: " << name << std::endl;
    out << "Country: " << country << std::endl;
    out << "Count: " << count << std::endl;
    out << "Data:"<< std::endl;
    for(int i = 0; i < count; i++) {
        out << data[i] << ", ";
    }
    out << std::endl;
    out << "Worc: ";
    ::Print_time(time[0]);
    out << ":";
    ::Print_time(time[1]);
    out  << " - ";
    ::Print_time(time[2]);
    out << ":";
    ::Print_time(time[3]);
    out << std::endl;
    out << "Cost: " << cost << std::endl;
    out << "___________" << std::endl;
}
void Zoo::Print() const {
    cout << "Name: " << name << std::endl;
    cout << "Country: " << country << std::endl;
    cout << "Count: " << count << std::endl;
    cout << "Data:"<< std::endl;
    for(int i = 0; i < count; i++) {
        cout << data[i] << ", ";
    }
    cout << std::endl;
    cout << "Worc: ";
    ::Print_time(time[0]);
    cout << ":";
    ::Print_time(time[1]);
    cout  << " - ";
    ::Print_time(time[2]);
    cout << ":";
    ::Print_time(time[3]);
    cout << std::endl;
    cout << "Cost: " << cost << std::endl;
    cout << "___________" << std::endl;
}

string Zoo::Get_name() const {
    return name ;
}

string Zoo::Get_country() const {
    return country;
}

int Zoo::Get_count() const {
    return count;
}

string * Zoo::Get_data() const {
    return data;
}

int * Zoo::Get_time() const {
    return time;
}

int Zoo::Get_cost() const {
    return cost;
}

void Zoo::Print_name(ofstream& out) const {
    out << name << std::endl;
}
void Zoo::Print_name() const {
    cout << name << std::endl;
}

void Zoo::Print_country(ofstream &out) const {
    out << country << std::endl;
}
void Zoo::Print_country() const {
    cout << country << std::endl;
}

void Zoo::Print_count(ofstream &out) const {
    out << count << std::endl;
}
void Zoo::Print_count() const {
    cout << count << std::endl;
}

void Zoo::Print_data(ofstream &out) const {
    for(int i = 0; i < count; i++) {
        out << data[i] << ", ";
    }
    out << std::endl;
}
void Zoo::Print_data() const {
    for(int i = 0; i < count; i++) {
        cout << data[i] << ", ";
    }
    cout << std::endl;
}

void Zoo::Print_time(ofstream &out) const {
    ::Print_time(time[0], out);
    out << ":";
    ::Print_time(time[1], out);
    out << " - ";
    ::Print_time(time[2], out);
    out << ":";
    ::Print_time(time[3], out);
    out << std::endl;
}
void Zoo::Print_time() const {
    ::Print_time(time[0]);
    cout << ":";
    ::Print_time(time[1]);
    cout << " - ";
    ::Print_time(time[2]);
    cout << ":";
    ::Print_time(time[3]);
    cout << std::endl;
}

void Zoo::Print_cost(ofstream& out) const {
    out << cost << std::endl;
}
///Users/dmitriygarkin/CLionProjects/lab_1_1

void Zoo::Change_name(string new_name) {
    name = new_name;
}

void Zoo::Change_country(string new_country) {
    country = new_country;
}

void Zoo::Change_data(string* new_data, int new_count) {
    count = new_count;
    if(count < 0) {
        cout << "u can't change count in this way";
        exit(0);
    }
    delete[] data;
    data = new string[count];
    for(int i = 0; i < count; i++) {
        data[i] = new_data[i];
    }
}

void Zoo::Change_time(int * new_time) {
    if(time[0]<0||time[0]>24||time[1]<0||time[1]>59||time[2]<0
       ||time[2]>24||time[3]<0||time[3]>59) {
        cout << "u can't change time in this way";
        exit(0);
    }
    time[0] = new_time[0];
    time[1] = new_time[1];
    time[2] = new_time[2];
    time[3] = new_time[3];
}

void Zoo::Change_cost(int new_cost) {
    if(cost < 0) {
        cout << "u can't change cost in this way";
        exit(0);
    }
    cost = new_cost;
}

int Zoo::How_much(int n) {
    if(n < 0) {
        cout << "отрицательное время?";
        exit(0);
    }
    int res;
    int all_time;
    if(time[3] >= time[1]) {
        all_time = (time[2] - time[0])*60 + time[3] - time[1];
    } else {
        all_time = (time[2] - time[0] - 1)*60 + time[3] + 60 - time[1];
    }
    res = all_time/n;
    //вывожу минимум, тк нельзя обойти животных больше, чем их есть
    //в зоопарке всего
    res = res>count? count:res;
    return res;
}
