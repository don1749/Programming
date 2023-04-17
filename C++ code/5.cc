#include <iostream>
#include <assert.h>
using namespace std;

class stack {
    private:
        int max;
        int *data = new int[max];
        int sp;
    public:
        bool empty() {return sp==0;};
        void push(int d ) {
            assert(sp<max); data[sp++]=d;
            cout << "Pushed " << d << endl;
        };
        int top() {return data[sp-1];};
        void pop() {
            assert(0<sp);
            cout << "Popped " << data[sp-1] << endl;
            --sp;
        };
        int size() {return sp;};
        friend bool equal(const stack&, const stack&);
        stack(int sz=100) {
            sp = 0;
            max = sz;
            data = new int[max];
            cout << "Initializing stack with maximum size " << max << endl;
        };
        ~stack() {delete [] data;};
};

bool equal(const stack& s1, const stack& s2) {
    bool eq=true;
    if (s1.sp != s2.sp) eq = false;
    else {
        for(int j=0; j<s1.sp && eq; j++)
            eq = (s1.data[j] == s2.data[j]); 
    }
    return eq;
}

int main() {
    stack s1, s2;
    cout << "s1 "; s1.push(5);
    cout << "s1 "; s1.push(8);
    cout << "s1 "; s1.push(9);
    cout << "s2 "; s2.push(5);
    cout << "s2 "; s2.push(8);
    cout << "s2 "; s2.push(9);
    cout << "s2 "; s2.push(10);
    
    if (equal(s1, s2)) cout << "Two stacks are equal." << endl;
    else cout << "Two stacks are not equal." << endl;
    cout << "s2 "; s2.pop();
    if (equal(s1, s2)) cout << "Two stacks are equal." << endl;
    else cout << "Two stacks are not equal." << endl;

    return 0;
}