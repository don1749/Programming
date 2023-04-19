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
        stack(int sz=100) {
            sp = 0;
            max = sz;
            data = new int[max];
            cout << "Initializing stack with maximum size " << max << endl;
        };
        ~stack() {delete [] data;};
};

int main() {
    stack s(2);
    s.push(5);
    s.push(8);
    s.push(9);
    cout << "Current stack size: " << s.size() << endl;
    s.pop();
    s.pop();
    s.push(3);
    cout << "Current stack size: " << s.size() << endl;

    while(!s.empty()) {
        cout << "Current stack top: " << s.top() << endl;
        s.pop();
    }
    return 0;
}