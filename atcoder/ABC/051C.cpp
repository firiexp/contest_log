#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;



int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = c - a, y = d-b;
    string s;
    for (int i = 0; i < x; ++i) {
        s += "R";
    }
    for (int j = 0; j < y; ++j) {
        s += "U";
    }
    for (int i = 0; i < x; ++i) {
        s += "L";
    }
    for (int j = 0; j < y; ++j) {
        s += "D";
    }
    s += "D";
    for (int i = 0; i < x+1; ++i) {
        s += "R";
    }
    for (int j = 0; j < y+1; ++j) {
        s += "U";
    }
    s += "LU";
    for (int i = 0; i < x+1; ++i) {
        s += "L";
    }
    for (int j = 0; j < y+1; ++j) {
        s += "D";
    }
    s += "R";
    cout << s << "\n";
    return 0;
}
