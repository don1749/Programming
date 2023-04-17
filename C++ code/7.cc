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
int main() {
    Complex x,y,z,a,b,c;
    x = Complex(1.00,2.00);
    y = Complex(2.22, 3.14);
    z = Complex(4.23, 9.99);
    a = x+y+z;
    b = x-y;
    c = x*y;

    cout << "x = ";  x.print(cout); cout << endl;
    cout << "y = "; y.print(cout); cout << endl;
    cout << "z = "; z.print(cout); cout << endl;
    cout << "a = x+y+z = "; a.print(cout); cout << endl;
    cout << "b = x-y = "; b.print(cout); cout << endl;
    cout << "c = x*y = "; c.print(cout); cout << endl;
    return 0;
}