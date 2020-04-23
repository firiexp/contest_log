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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> v(w+1), u(h+1);
    for (int i = 0; i < n; ++i) {
        int x, y, p;
        scanf("%d%d%d", &x, &y, &p);
        v[max(0, x-p)]++; v[min(w, x+p)]--;
        u[max(0, y-p)]++; u[min(h, y+p)]--;
    }
    int ok = 1;
    for (int i = 0; i < w; ++i) {
        v[i+1] += v[i];
        if(v[i] == 0) {
            ok = 0;
        }
    }
    if(ok){
        puts("Yes");
        return 0;
    }
    ok = 1;
    for (int i = 0; i < h; ++i) {
        u[i+1] += u[i];
        if(u[i] == 0) {
            ok = 0;
        }
    }
    if(ok){
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}