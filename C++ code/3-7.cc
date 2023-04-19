#include <iostream>
#include <assert.h>
using namespace std;

class stack {
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int sz) {sp=0; max=sz; data=new int[max]; cout << "stack (" << sz << ")" << endl; cout << &data << endl; }
        ~stack() {cout << 1; delete [] data; cout << "~stack (" << max << ")" << endl; }
        bool empty() {return sp==0;}
        void push(int d) {assert(sp<max); data[sp++]=d;}
        void pop() {assert(0<sp); --sp;}
        int top() {return data[sp-1];}
        int size() {return sp;}
        void dump(ostream&);
        stack& operator=(const stack&);
};

stack& stack::operator=(const stack& s) {
    if(&s!=this) {
        if(max<s.sp) {
            delete [] data;
            data=new int[max=s.max];
        }
        sp=s.sp;
        for(int i=0; i<sp; i++) data[i]=s.data[i];
    }
    cout << "operator=(const stack&)" << endl;
    return *this;
}

void stack::dump(ostream& os) {
    cout << "max=" << max << ", ";
    cout << "sp=" << sp << ", ";
    cout << "data=(";
    for (int i=0; i<max; i++) os << data[i] << " ";
    os << ")" << endl;
}

stack plus1(stack s1, stack s2) {
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);
    while(!s2.empty()) {tmp.push(s2.top()); s2.pop();}
    while(!s1.empty()) {tmp.push(s1.top()); s1.pop();}
    while(!tmp.empty()) {s.push(tmp.top()); tmp.pop();}
    // cout << &s1 << endl << &s2 << endl << &tmp << endl << &s << endl;
    return s;
}

int main() {
    stack s1(5);
    stack s2(6);
    stack s(10);

    s1.push(1); s1.push(3); s1.push(5);
    s2.push(2); s2.push(4); s2.push(6);
    // s1.dump(cout);
    // s2.dump(cout);

    s = plus1(s1,s2);

    s1.dump(cout);
    s2.dump(cout);
    s.dump(cout);

    // cout << &s1 << endl << &s2 << endl << &s << endl;

    return 0;
}
