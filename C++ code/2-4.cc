#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<double, int> fmap;
    fmap[80.00] = 21;
    fmap[82.50] = 33;
    fmap[86.66] = 44;
    
    // List 2.8
    cout << "---List 2.8---" << endl;
    cout << fmap[80.00] << endl;
    cout << fmap[82.50] << endl;
    cout << fmap[86.66] << endl;
    cout << fmap[92.13] << endl;
    // 未定義の要素に対しては, データのデフォルト値 (int 型の場合は 0) が返される

    // List 2.10
    cout << "---List 2.10---" << endl;
    map<double, int>::iterator p;
    for (p = fmap.begin(); p != fmap.end(); ++p) {
        cout << p->first << ": " << p->second << endl;
    }

    // List 2.11
    cout << "---List 2.11---" << endl;
    double f; cin >> f;
    string dummy; getline(cin, dummy);
    if ((p=fmap.find(f)) == fmap.end())
        cout << "Not found" << endl;
    else {
        cout << p->first << ": " << p->second << endl;
        fmap.erase(p);
    }

    // Change key format from double to string
    map<string, int> smap;
    map<string, int>::iterator it;
    smap["a"] = 1; smap["a b"] = 2; smap["c"] = 3;

    cout << "---String as key---" << endl;
    cout << "Key string: "; string s; getline(cin, s);

    if ((it=smap.find(s)) == smap.end())
        cout << "Not found" << endl;
    else
        cout << it->first << ": " << it->second << endl;

    return 0;
}