#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Entry {
    public:
        string name;
        string phone;
        Entry (const string& nm="", const string& ph="") {
            name = nm;
            phone = ph;
        }
};

class by_name {
    public:
        bool operator() (const Entry& e1, const Entry& e2) const {
            return e1.name < e2.name;
        }
};

class by_phone {
    public:
        bool operator() (const Entry& e1, const Entry& e2) const {
            return e1.phone < e2.phone;
        }
};

ostream& operator<< (ostream& os, const Entry& e) {
    os << e.name << ": " << e.phone;
    return os;
}

int main() {
    vector<Entry> e;

    e.push_back(Entry("university of tokyo", "03-3812-2111"));
    e.push_back(Entry("osaka university", "06-879-7806"));
    e.push_back(Entry("kinki university", "06-721-2332"));
    e.push_back(Entry("osaka prefectural university", "0722-52-1161"));
    e.push_back(Entry("kyoto university", "075-753-7531"));

    for (int i=0; i<e.size(); i++) {
        if (e[i].phone.substr(0, 3) == "06-") {
            e[i].phone.insert(3, "6");
            // cout << (cout, e[i]); cout << endl;
        }
    }
    
    //sort
    cout << "---Sort by name---\n";
    sort(e.begin(), e.end(), by_name());
    for (int i = 0; i <e.size(); i++) cout << e[i] << endl;

    cout << "---Sort by phone---\n";
    sort(e.begin(), e.end(), by_phone());
    for (int i =0; i <e.size(); i++) cout << e[i] << endl;

    //find directory
    cout << "---Find directory---\n";
    cout << "directory service: ";
    string dir; getline(cin, dir);
    for (int i=0; i<e.size(); i++) {
        if (e[i].name == dir) {
            cout << e[i] << endl;
            return 0;
        }
    }
    cout << "Directory not found!" << endl;
    return 0;
}