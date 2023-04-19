#include <iostream>
#include <string>
#include <list>
using namespace std;

class Record {
  public:
    int id;
    string name;
    int score;
    Record() {}
    Record(int i, const string& nm, int s) {
      id = i;
      name = nm;
      score = s;
    }
};

ostream& operator<<(ostream& os, const Record& r) {
  os << "[" << r.id << "] " << r.name << " : " << r.score;
  return os;
}

class Seiseki {
  public:
    list<Record> data;
    void insert(int, const string&, int);
    void lookup(int);
    void erase_worst();
};

ostream& operator<<(ostream& os, const Seiseki& s) {
  os << "*** Seiseki ***\n";
  for (list<Record>::const_iterator p = s.data.begin(); p != s.data.end(); p++) {
    os << *p << "\n";
  }
  return os;
}

void Seiseki::insert(int id, const string& nm, int s) {
  Record r(id, nm, s);
  data.push_back(r);
}

void Seiseki::lookup(int id) {
  bool found = false;
  for (list<Record>::iterator p = data.begin(); p != data.end(); p++) {
    if (p->id == id) {
        found = true;
        cout << *p << "\n";
        break;
    }
  }
  if(!found) cout << "Not found" << endl;
}

void Seiseki::erase_worst() {
  list<Record>::iterator worst;
  int MIN = 1e7;
  for (list<Record>::iterator p = data.begin(); p != data.end(); p++) {
    if (p->score < MIN) {
        MIN = p->score;
        worst = p;
    }
  }
  data.erase(worst);
}


int main(int ac, char** av)
{
  Seiseki s;
  s.insert(7001,"aaaa",89);
  s.insert(7123,"bbbb",70);
  s.insert(7013,"cccc",55);
  s.insert(7200,"dddd",99);
  s.insert(7087,"eeee",83);

  cout << s;

  int id;
  cout << "> ";
  cin >> id;
  while (id!=0) {
    s.lookup(id);
    cout << "> ";
    cin >> id;
  }

  s.erase_worst();
  cout << s;

  return 0;
}