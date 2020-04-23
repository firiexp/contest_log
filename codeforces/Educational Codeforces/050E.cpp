#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;
#define EPS (1e-10)
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y) :x(x),y(y){}
    Point operator+(Point p) {return Point(x+p.x,y+p.y);}
    Point operator-(Point p) {return Point(x-p.x,y-p.y);}
    Point operator*(double k){return Point(x*k,y*k);}
    Point operator/(double k){return Point(x/k,y/k);}
    double norm(){return x*x+y*y;}
    double abs(){return sqrt(norm());}

    bool operator < (const Point &p) const{
        return x!=p.x?x<p.x:y<p.y;
        //grid-point only
        //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    }
};

struct EndPoint{
    Point p;
    int seg,st;
    EndPoint(){}
    EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}
    bool operator<(const EndPoint &ep)const{
        if(p.y==ep.p.y) return st<ep.st;
        return p.y<ep.p.y;
    }
};

istream &operator >> (istream &is,Point &p){
    is>>p.x>>p.y;
    return is;
}

ostream &operator << (ostream &os,Point p){
    os<<fixed<<setprecision(12)<<p.x<<" "<<p.y;
    return os;
}

bool sort_x(Point a,Point b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

bool sort_y(Point a,Point b){
    return a.y!=b.y?a.y<b.y:a.x<b.x;
}

typedef Point Vector;
typedef vector<Point> Polygon;

istream &operator >> (istream &is,Polygon &p){
    for (auto &i : p) cin>> i;
    return is;
}

struct Segment{
    Point p1,p2;
    Segment(){}
    Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

istream &operator >> (istream &is,Segment &s){
    is>>s.p1>>s.p2;
    return is;
}

int main() {
    int n;
    cin >> n;

    return 0;
}
