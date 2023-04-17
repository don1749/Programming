#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
}

int main() {
    int a, b;
    cout << "Before swap:" << endl;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;

    swap(a, b);
    cout << "After swap:" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl << endl;

    return 0;
}