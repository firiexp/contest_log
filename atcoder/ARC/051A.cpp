#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;



int main() {
    int x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
    if(x2+r <= x1 && x1 + r <= x3 && y2+r <= y1 && y1+r <= y3) cout << "NO\n";
    else cout << "YES\n";
    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= r*r &&
       (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) <= r*r &&
       (x1-x3)*(x1-x3)+(y1-y2)*(y1-y2) <= r*r &&
       (x1-x2)*(x1-x2)+(y1-y3)*(y1-y3) <= r*r ) cout << "NO\n";
    else cout << "YES\n";

    return 0;
}
