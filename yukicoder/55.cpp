#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T>
struct Point: public pair<T, T> {
    T x = this->first;
    T y = this->second;
    explicit Point(T x = 0,T y = 0): pair<T, T>(x, y) {};
};

int main() {
    vector<Point<int>> v(3);
    for (int i = 0; i < 3; ++i) {
        int a, b;
        scanf("%d %d",&a, &b);
        v[i] = Point<int>(a, b);
    }
    sort(v.begin(), v.end());
    do {
        if((v[1].x-v[0].x)*(v[2].x-v[1].x) != (v[0].y-v[1].y)*(v[2].y-v[1].y)) continue;
        if((v[1].x-v[0].x)*(v[1].x-v[0].x)+(v[1].y-v[0].y)*(v[1].y-v[0].y) !=
                (v[2].x-v[1].x)*(v[2].x-v[1].x)+(v[2].y-v[1].y)*(v[2].y-v[1].y))
            continue;
        cout << v[0].x + v[2].x-v[1].x << " " << v[0].y + v[2].y - v[1].y << "\n";
        return 0;
    }while(next_permutation(v.begin(), v.end()));
    puts("-1");
    return 0;
}
