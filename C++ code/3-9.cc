#include <iostream>
#include <assert.h>
using namespace std;

//Complex
class Complex {
  private:
    double real;
    double imag;
  public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}
    ~Complex() {}
    Complex& operator=(const Complex& c) {
      real = c.real; imag = c.imag;
      return *this;
    }
    double re() {return real;}
    double im() {return imag;}
    void set_re(double r) {real = r;}
    void set_im(double i) {imag = i;}
    void print(ostream& os) {
        if(imag < 0.0) os << real << " - " << -imag << "i";
        else os << real << " + " << imag << "i";
    };
};

ostream& operator<<(ostream& os, Complex& c) {
  c.print(os);
  return os;
}

Complex operator+(Complex a, Complex b) {
  Complex c;
  c.set_re(a.re() + b.re());
  c.set_im(a.im() + b.im());
  return c;
}

//stack
class stack {
    private:
        int sp;
        int max;
        int* data;
    public:
        stack(int);
        ~stack() {delete [] data;}
        bool empty() {return sp==0;}
        void push(int d) {assert(sp<max); data[sp++]=d;}
        void pop() {assert(0<sp); --sp;}
        int top() {return data[sp-1];}
        int size() {return sp;}
        void dump(ostream&);
        stack& operator=(const stack&);
        stack(const stack&);
};

stack::stack(int sz) : max(sz), sp(0) {data = new int[max];}

stack& stack::operator=(const stack& s) {
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

void stack::dump(ostream& os) {
    cout << "max=" << max << ", ";
    cout << "sp=" << sp << ", ";
    cout << "data=(";
    for (int i=0; i<sp; i++) os << data[i] << " ";
    os << ")" << endl;
}

stack plus1(stack s1, stack s2) {
    int sz = s1.size() + s2.size();
    stack tmp(sz), s(sz);
    while(!s2.empty()) {tmp.push(s2.top()); s2.pop();}
    while(!s1.empty()) {tmp.push(s1.top()); s1.pop();}
    while(!tmp.empty()) {s.push(tmp.top()); tmp.pop();}
    return s;
}

stack::stack(const stack& s) {
    max = s.max;
    sp = s.sp;
    data = new int[max];
    for (int i=0; i<sp; i++) data[i]=s.data[i];
}

int main() {
    //Complex
    cout << "---Complex---" << endl;
    Complex x(3.14, 2.26);
    Complex y = x;
    Complex z;
    z = x+y;

    cout << z << endl;

    // stack
    cout << "----stack----" << endl;
    stack s1(5);
    stack s2(5);
    stack s(10);

    s1.push(1); s1.push(3); s1.push(5);
    s2.push(2); s2.push(4); s2.push(6);

    s = plus1(s1,s2);

    s1.dump(cout);
    s2.dump(cout);
    s.dump(cout);

    return 0;
}
