#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        for (int i = 0; i < n; ++i) {
            int a, b, c, d, e, f, g, h;
            cin >> a >> b >> c >> d >> e >> f >> g >> h;
            printf("%d %d %d %d\n",
                   a*e-b*f-c*g-d*h,
                   a*f+b*e+c*h-d*g,
                   a*g-b*h+c*e+d*f,
                   a*h+b*g-c*f+d*e
            );
        }
    }
    return 0;
}