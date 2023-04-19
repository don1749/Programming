#include <iostream>
#include <string>
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

ostream& operator<< (ostream& os, const Entry& e) {
    os << e.name << ": " << e.phone;
    return os;
}

int main() {
    Entry e[10];
    int n = 0;
    e[n++] = Entry("university of tokyo", "03-3812-2111");
    e[n++] = Entry("osaka university", "06-879-7806");
    e[n++] = Entry("kinki university", "06-721-2332");
    e[n++] = Entry("osaka prefectural university", "0722-52-1161");
    e[n++] = Entry("kyoto university", "075-753-7531");
    for (int i=0; i<n; i++) {
        // 大阪の局番 4 桁化
        if (e[i].phone.substr(0, 3) == "06-") {
            e[i].phone.insert(3, "6");
        }
    }
    cout << "directory service: ";
    // 文字列を入力し, その電話番号を検索し, 出力
    string dir; getline(cin, dir);
    for (int i=0; i<n; i++) {
        if (e[i].name == dir) {
            cout << e[i] << endl;
            return 0;
        }
    }
    cout << "Directory not found!" << endl;
    return 0;
}