#include <iostream>
using namespace std;

class Complex {
    private:
        double real, imag;
    public:
        Complex() {real = 0.0; imag = 0.0;};
        Complex(double r, double i) {real = r; imag = i;};
        Complex(double r) {real = r; imag = 0.0;};
        ~Complex(){};
        void assign(const Complex&);
        Complex& operator=(const Complex&);
        Complex& operator+=(const Complex&);
        void print(ostream& os) {
            if(imag < 0.0) os << real << " - " << -imag << "i";
            else os << real << " + " << imag << "i";
        };
};


void Complex::assign(const Complex& c) {
    real = c.real;
    imag = c.imag;
}

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& c) {
    real += c.real;
    imag += c.imag;
    return *this;
}

inline ostream& operator<<(ostream& os, Complex& c) {
    c.print(os);
    return os;
}

int main() {
    Complex a = Complex(1,2);
    Complex b; b.assign(a);
    Complex c = Complex(); c+=a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}