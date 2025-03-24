#include <iostream>

using namespace std;


class Point{
    public:
    int x, y;
    Point() : x(0), y(0) {};
    Point(int x_, int y_) : x(x_), y(y_){};
};

class Rect : public Point{
    public:
    int a; // ширина
    int b; // высота

    
    Rect () : a(1), b(1), Point(){};
    Rect (int x_, int y_, int a_, int b_) : a(a_), b(b_), Point(x_, y_){};
    Rect operator * (const int k) const{

        return Rect(this->x, this->y, this->a * k, this->b * k); 
    }
    bool operator < (const Rect& r){
        if (this->x != r.x)
            return this->x < r.x;
        return this->y < r.y;
    }

    friend Rect& operator-- (Rect& r){
        r.a -=  1;
        r.b -= 1;
        return r; 
    }


};
ostream& operator << (ostream& os, Rect& r) {
    os << " x = " << r.x << " y = " << r.y << " a=" << r.a << " b=" << r.b << '\n';
    return os;
}

istream& operator>>(istream& is, Rect& r) {
    int x_, y_, a_, b_;
    is >> x_ >> y_ >> a_ >> b_;
    if (is){
        r.x = x_;
        r.y = y_;
        r.a = a_;
        r.b = b_;
    }
    return is;
}

int main(){
    Rect a;
    cin >> a;
    Rect b (1, 2, 3, 4);
    cout << b;
    b = b*1;
    cout << b;
    --b;
    cout << b;
    if (a < b){
        cout << "<\n";
    }
    else cout << ">=\n";
}