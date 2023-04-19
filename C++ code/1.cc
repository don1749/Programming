#include <iostream>
using namespace std;

/* Generate Fibonacci series*/
int main() {
    int n;
    int errorCount = 0;

    while(errorCount < 3) {
        cout << "Input series size: ";
        cin >> n;

        if (n<=0 || n>94) {
            cout << "Please input a valid size (0<n<95)" << endl << endl;
            errorCount++;
            continue;
        }

        if (n==1) {
            cout << "The first Fibonacci number is 1" << endl;
            return 0;
        }

        cout << endl << "The first " << n << " Fibonacci numbers" << endl;

        unsigned long long a,b,c; // Maximum value~1.8x10^19
        
        a = 0; b = 1;
        cout << 0 << ": " << a << endl;
        cout << 1 << ": " << b << endl;

        for (int i=2; i<n; i++) {
            c = a+b;
            cout << i << ": " << c << endl;
            a = b;
            b = c;
        }

        return 0;
    }
    cout << "Too much invalid inputs!" << endl;

    return 0;
}