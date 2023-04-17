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
        void print(ostream& os) {os << real << "+" << imag << "i";};
};

int main() {
    Complex a;
    a.set_re(1.11);
    a.set_im(2.22);
    Complex b(3.33, 4.44);
    Complex c;
    c = Complex(9.99, 88.88);
    cout << "a = "; a.print(cout); cout << endl;
    cout << "b = "; b.print(cout); cout << endl;
    cout << "c = "; c.print(cout); cout << endl;

    c = a;
    cout << "c = "; c.print(cout); cout << endl;

    Complex d = Complex(7.77);
    cout << "d = "; d.print(cout); cout << endl;
    return 0;
}