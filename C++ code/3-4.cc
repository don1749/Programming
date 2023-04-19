#include <iostream>
#include <assert.h>
using namespace std;

class stack {
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int sz) {sp=0; max=sz; data=new int[max]; cout << "stack (" << sz << ")" << endl;}
        ~stack() {delete [] data; cout << "~stack (" << max << ")" << endl;}
        bool empty() {return sp==0;}
        void push(int d) {assert(sp<max); data[sp++]=d;}
        void pop() {assert(0<sp); --sp;}
        int top() {return data[sp-1];}
        int size() {return sp;}
        void dump(ostream&);
};

void stack::dump(ostream& os) {
    cout << "max=" << max << ", ";
    cout << "sp=" << sp << ", ";
    cout << "data=(";
    for (int i=0; i<sp; i++) os << data[i] << " ";
    os << ")" << endl;
}

int main() {
    stack s1(5), s2(7);

    s1.push(1); s1.push(3); s1.push(5);

    s2 = s1;

    s1.pop(); s1.pop(); s1.push(300); s1.push(500);

    s1.dump(cout); s2.dump(cout);

    return 0;
}
