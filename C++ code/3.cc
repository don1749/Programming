#include <iostream>
#include <assert.h>
using namespace std;

class stack {
    private:
        static const int max = 100;
        int data[max];
        int sp;
    public:
        bool empty();
        void push(int);
        int top();
        void pop();
        int size();
        stack();
        ~stack();
};

bool stack::empty() {
    return sp == 0;
}

void stack::push(int d) {
    assert(sp < max);
    data[sp++] = d;
}

int stack::top() {
    return data[sp-1];
}

void stack::pop() {
    assert(0 < sp);
    --sp;
}

int stack::size() {
    return sp;
}

stack::stack() {sp=0;}

stack::~stack(){}

int main() {
    stack s;
    s.push(5);
    s.push(8);
    s.push(9);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    s.push(3);
    cout << s.size() << endl;

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}