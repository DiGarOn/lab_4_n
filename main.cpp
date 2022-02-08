#include <iostream>
#include "MyDeck.h"
//#include "MyDeck_n.h"
using std::cout;

struct A {
    int data = 1;
    void Print() {
        cout << data;
    }
}b;

int main() {
    /*
    Zoo val;
    
    MyStack<Zoo> stack(2);
    */
    /*
    stack.push_back(val);
    stack.Print();

    cout << "_________________" << endl;

    MyStack<Zoo> stack_2(2);
    stack_2 = stack;
    stack_2.Print();

    val = stack.pop_back();
    cout << "empty stack" << endl;
    cout << stack;
    cout << "empty stack" << endl;

    val = stack_2.top();

    val.Print();

    cout << std::boolalpha << stack.isEmpty();
    cout << std::boolalpha << stack_2.isEmpty();

    cout << "вызов функции сравнения " << std::boolalpha << (stack == stack_2); 
    cout << endl << endl << endl << endl;
    */
    
    /*
    MyStack<Zoo> new_stack(2);
    new_stack = stack;
    new_stack.push_front(val);
    cout << new_stack;
    val = new_stack.pop_front();
    cout << std::boolalpha << new_stack.isEmpty();
    */

    MyDeck<int> deque(10);
    deque.push_back(3);
    deque.push_back(4);
    deque.push_back(5);
    deque.push_back(6);
    deque.push_back(7);
    deque.push_front(2);
//234567


    std::cout << deque.pop_front() << std::endl;
//->2
    std::cout << deque.pop_front() << std::endl;
//->3
    std::cout << deque.pop_back() << std::endl;
//->7
    std::cout << deque.pop_back() << std::endl;
//->6
//45
    deque.push_front(9);
//945
    std::cout << deque.pop_front() << std::endl;
//->9
    deque.push_front(11);
    deque.push_front(10);
    deque.push_front(9);
    deque.push_front(8);
//89101145



    std::cout << deque.pop_back() << std::endl;
//->5
    cout << "__________________________" << endl;

    MyDeck<int> d(10); 
    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    d.push_front(4);
    d.push_front(5);
    cout << d.pop_back() << endl;
    cout << d.pop_back() << endl;
    cout << d.pop_back() << endl;
    cout << d.pop_back() << endl;
    cout << d.pop_back() << endl;
    d.push_front(1);
    
    cout << std::boolalpha << (d==deque) << endl;

    MyDeck<int> c(1);
    c.push_back(1);
    cout << c.size() << " ";
    c.push_front(2);
    cout << c.size() << " ";
    c.push_back(2);

    cout << "___________________" << endl;

    //deque.Print();
    cout << endl << "here" << endl; 
    cout << deque;
    cout << d;
      
    cout << endl << endl << "-------------->Zoo: " << endl;
    Zoo a;
    MyDeck<Zoo> zoo_deck(10);
    zoo_deck.push_back(a);
    
    string new_name = "zoo"; 
    string new_coutry = "rus";
    string new_data[2];
    string data_0, data_1;
    data_0 = "11";
    data_1 = "12";
    new_data[0] = data_0;
    new_data[1] = data_1;
    int new_count = 2;
    int new_time [4];
    new_time[0] = 0;
    new_time[1] = 1;
    new_time[2] = 1;
    new_time[3] = 2;  
    int new_cost = 100;

    Zoo zoo(new_name, new_coutry, new_data, new_count, new_time, new_cost);
    zoo.Print();
    zoo_deck.push_front(zoo);
    
    cout << zoo_deck;
    


    /*
    тут код работать не будет, выдаст ошибку
    cout << "----------------->A: " << endl;
    MyDeck<A> a_deck(10);
    a_deck.push_back(b);
    cout << a_deck;
    */

    return 0;
}
