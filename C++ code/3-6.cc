#include <iostream>
using namespace std;

class Complex {
  private:
    double real;
    double imag;
  public:
    Complex() {
      real = 0.0; imag = 0.0;
      cout << "Complex()" << endl;
    }
    Complex(double r, double i) {
      real = r; imag = i;
      cout << "Complex(" << r << "," << i << ")" << endl;
    }
    Complex(const Complex& c) {
      real = c.real; imag = c.imag;
      cout << "Complex(const Complex&)" << endl;
    }
    ~Complex() {cout << "~Complex()" << endl;}
    Complex& operator=(const Complex& c) {
      real = c.real; imag = c.imag;
      cout << "operator=(const Complex& c)" << endl;
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

int main() {
  Complex x(3.14, 2.26);
  Complex y = x;
  Complex z;
  z = x+y;

  cout << z << endl;
  return 0;

}
