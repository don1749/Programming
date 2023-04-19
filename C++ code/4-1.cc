#include <iostream>
#include <string>
using namespace std;

class car {
    public:
        string model;
        string maker;
        int displacement;
        int ps;
        int weight;
    public:
        car() {}
        car(const string& md, const string& mk, int dp, int p, int w):
            model(md), maker(mk), displacement(dp), ps(p), weight(w) {}
        ~car() {}

        int no() const {
            if(displacement < 2000) return 5;
            else return 3;
        }
        double pwratio() const {
            return (double) weight / (double) ps;
        }
        int tax() const {
            if(weight < 1300) return 34000;
            else return 43000; 
        }
};

class hybrid_car: public car {
    public:
        int motor_ps;
    public:
        hybrid_car() {}
        hybrid_car(
            const string& md,
            const string& mk,
            int dp, int p, int w, int mps
        ) : car(md,mk,dp,p,w), motor_ps(mps) {}
    ~hybrid_car() {}

    double pwratio() const { return (double) weight/(double) (ps+motor_ps); }
    int tax() const {return 0;}
};

int main() {
    car a = car("Skyline", "Nissan", 2987, 260, 1490);
    car b = car("Accord", "Honda", 1997, 180, 1290);
    hybrid_car h = hybrid_car("Prius", "Toyota", 1498, 60, 1235, 20);
    cout << a.model << " "<< a.no() << " "<< a.pwratio() << " " << a.tax() << endl;

    cout << b.model << " " << b.no() << " " << b.pwratio() << " " << b.tax() << endl;

    cout << h.model << " " << h.no() << " " << h.pwratio() << " " << h.tax() << endl;

    return 0;
}