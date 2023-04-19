#include <iostream>
#include <string>
using namespace std;

inline int abs(int x) {return 0<=x ? x: -x;}

class canvas {
    public:
        canvas(int sx, int sy);
        ~canvas();
        void clear();
        void set(int x, int y);
        void print(ostream &os);
    private:
        int size_x;
        int size_y;
        char **p;
        canvas(const canvas&);
        canvas& operator=(const canvas&);
};

ostream& operator <<(ostream& os, canvas &c) {c.print(os); return os;}

canvas::canvas(int sx, int sy) : size_x(sx), size_y(sy) {
    p = new char* [size_x];
    for (int x=0; x<size_x; x++) p[x] = new char[size_y];
    this -> clear();
}

canvas::~canvas() {
    for (int x=0; x<size_x; x++) delete [] p[x];
    delete [] p;
}

void canvas::clear() {
    for (int x=0; x<size_x; x++)
        for (int y=0; y<size_y; y++)
            p[x][y] = ' ';
}

void canvas::set(int x, int y) {
    if (0<=x && x<size_x && 0<=y && y<size_y) p[x][y] = 'X';
}

void canvas::print(ostream& os) {
    os << '+';
    for (int x=0; x<size_x; x++) os << '-';
    os << '+' << endl;
    for (int y=size_y-1; 0<=y; y--) {
        os << '|';
        for (int x=0; x<size_x; x++) os << p[x][y];
        os << '|' << endl;
    }
    os << '+';
    for (int x=0; x<size_x; x++) os << '-';
    os << '+' << endl;
}

class obj {
    public:
        obj(int x, int y, const string& t);
        ~obj();
        void move(int ix, int iy);
        void draw(canvas &c);
    public:
        int px, py;
        string type;
};
obj::obj(int x, int y, const string& t) : px(x), py(y), type(t) {}
obj::~obj() {}
void obj::move(int ix, int iy) {px+=ix; py+=iy;}

class point: public obj {
    public:
        point(int x, int y);
        ~point();
        void draw(canvas &c);
};

point::point(int x, int y): obj(x, y, "point") {}
point::~point() {}
void point::draw(canvas &c) {c.set(px,py);}

class rectangle: public obj {
    private:
        int width, height;
    public:
        rectangle(int x, int y, int w, int h);
        ~rectangle();
        void draw(canvas &c);
};
rectangle::rectangle(int x, int y, int w, int h): obj(x,y, "rectangle"), width(w), height(h) {}
rectangle::~rectangle() {}
void rectangle::draw(canvas &c) {
    for (int x=px; x<px+width; x++)
        for (int y=py; y<py+height; y++)
            c.set(x,y);
}

class diamond: public obj {
    private:
        int radius;
    public:
        diamond(int x, int y, int r);
        ~diamond();
        void draw(canvas &c);
};
diamond::diamond(int x, int y, int r): obj(x,y,"diamond"), radius(r) {}
diamond::~diamond() {}
void diamond::draw(canvas &c) {
    if(0<=radius) {
        for (int r=-radius; r<=radius; r++) {
            int h = radius - abs(r);
            for (int s=-h; s<=h; s++) {
                c.set(px+r, py+s);
            }
        }
    }
}

int main() {
    point p1(0,0);
    point p2(17,9);
    point p3(19,2);
    rectangle r1(2,1,3,2);
    rectangle r2(7,7,6,2);
    diamond d1(2,7,2);
    diamond d2(15,3,4);

    canvas c(20,10);
    p1.draw(c);
    p2.draw(c);
    p3.draw(c);
    r1.draw(c);
    r2.draw(c);
    d1.draw(c);
    d2.draw(c);
    cout << c;

    p1.move(4,2);
    p2.move(4,2);
    r1.move(4,2);
    r2.move(4,2);
    d1.move(4,2);
    d2.move(4,2);

    c.clear();
    p1.draw(c);
    p2.draw(c);
    p3.draw(c);
    r1.draw(c);
    r2.draw(c);
    d1.draw(c);
    d2.draw(c);
    cout << c;

    return 0;
}
