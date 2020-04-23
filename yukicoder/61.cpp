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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    int q;
    cin >> q;
    while(q--){
        int w, h, d, mx, my ,hx, hy, vx, vy;
        cin >> w >> h >> d >> mx >> my >> hx >> hy >> vx >> vy;
        int g = abs(__gcd(vx, vy));
        d *= g;
        vx /= g; vy /= g;
        int x = hx, y = hy;
        int ok = 0;
        for (int i = 0; i <= min(d, 1050); ++i) {
            int xx = abs(x+vx), yy = abs(y+vy);
            xx %= 2*w; yy %= 2*h;
            if(xx > w) xx = 2*w - xx;
            if(yy > h) yy = 2*h - yy;
            x += vx; y += vy;
            if(xx == mx && yy == my){
                ok = 1;
                break;
            }
        }
        puts(ok ? "Hit" : "Miss");
    }
    return 0;
}