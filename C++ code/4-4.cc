#include <iostream>
#include <assert.h>
using namespace std;

class stack {
    private:
        int sp;
        int max;
        int* data;
    public:
        stack() {}
        stack(int sz) {
            sp=0; max=sz; data=new int[max];
            cout << "stack (" << sz << ")" << endl; 
        }
        ~stack() {
            delete [] data;
            cout << "~stack(" << max << ")" << endl; 
        }
        bool empty() {return sp==0;}
        void push(int d) {
            assert(sp<max); 
            data[sp++]=d;
        }
        void pop() {
            assert(0<sp); 
            --sp;
        }
        int top() {return data[sp-1];}
        int size() {return sp;}
        void dump(ostream& os) {
            cout << "max=" << max << ", ";
            cout << "sp=" << sp << ", ";
            cout << "data=(";
            for (int i=0; i<sp; i++) os << data[i] << " ";
            os << ")" << endl;
        }
        stack& operator=(const stack& s) {
            cout << "operator=(const stack&)" << endl;
            if(&s!=this) {
                if(max<s.sp) {
                    delete [] data;
                    data=new int[max=s.max];
                }
                sp=s.sp;
                for(int i=0; i<sp; i++) data[i]=s.data[i];
            }
            return *this;
        }
        stack(const stack& s) {
            max = s.max;
            sp = s.sp;
            data = new int[max];
            for (int i=0; i<sp; i++) data[i]=s.data[i];
            cout << "stack(const stack& s) sp = " << sp << endl;
        }
};

class stack_ac: public stack {
    private:
        int push_count;
        int pop_count;
    public:
        stack_ac() {
            cout << "stack_ac()" << endl;
        }
        stack_ac(int sz): stack(sz), push_count(0), pop_count(0) {
            cout << "stack_ac(" << sz << ")" << endl;
        }
        ~stack_ac() {
            cout << "~stack_ac()" << endl;
        }
        void push(int d) {
            stack::push(d);
            push_count++;
        }
        void pop() {
            stack::pop();
            pop_count++;
        }
        int n_push() { return push_count;}
        int n_pop() { return pop_count;}
};

int main() {
    stack_ac s(5);

    s.push(1); s.push(2); s.pop(); s.push(3); s.pop();

    cout << "push count = " << s.n_push() << endl; 
    cout << "pop count = " << s.n_pop() << endl;

    return 0;
}