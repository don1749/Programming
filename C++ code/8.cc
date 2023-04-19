#include <iostream>
using namespace std;

class Complex {
    private:
        double real; double imag;
    public:
        Complex() {real = 0.0; imag = 0.0;};
        Complex(double r, double i) {real = r; imag = i;};
        Complex(double r) {real = r; imag = 0.0;};
        ~Complex(){};
        double re() {return real;};
        double im() {return imag;};
        void set_re(double r) {real = r;};
        void set_im(double i) {imag = i;};
        void print(ostream& os) {
            if(imag < 0.0) os << real << " - " << -imag << "i";
            else os << real << " + " << imag << "i";
        };
};

inline Complex operator+(Complex a, Complex b) {
    double r = a.re() + b.re();
    double i = a.im() + b.im();
    return Complex(r, i);
}

inline Complex operator-(Complex a, Complex b) {
    double r = a.re() - b.re();
    double i = a.im() - b.im();
    return Complex(r, i);
}

inline Complex operator*(Complex a, Complex b) {
    double r = a.re() * b.re() - a.im() * b.im();
    double i = a.re() * b.im() + a.im() * b.re();
    return Complex(r, i);
}

inline ostream& operator<<(ostream& os, Complex& c) {
    c.print(os);
    return os;
}

int main() {
    Complex a[3];
    a[0] = Complex(1.00, 2.00);
    a[1] = a[0] + Complex(0.00, 1.00);
    Complex *c = &(a[2]);
    *c = a[0];
    for(int i=0; i<3; i++) cout << a[i] << endl;
    Complex *b = new Complex[3];
    for(int i=0; i<3; i++) b[i] = a[i] + Complex(1.00, 1.00);
    for(int i=0; i<3; i++) cout << b[i] << endl;
    delete[] b;
    return 0;
}