#include <iostream>
#include "MyDeck.h"

using std::cout;

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

    MyDeck<int> deque;
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

    MyDeck<int> d;
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
    return 0;
    return 0;
}
