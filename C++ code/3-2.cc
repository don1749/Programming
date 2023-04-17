#include <iostream>
#include <string>
using namespace std;

class trace {
    private:
        string name;
    public:
        trace (const string& nm) {
            name = nm;
            cerr << name << " begin" << endl;
        }
        ~trace () {
            cerr << name << " end" << endl;
        }
};

int add (int a, int b) {
    trace t("add");
    return a+b;
}

int main() {
    trace t1("main");
    for (int i = 0; i <3; i++) {
        trace t2("for-loop");
        int c = add(i, i*i);
    }
    return 0;
}