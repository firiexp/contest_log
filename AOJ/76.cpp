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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, ~n){
        double x = 1, y = 0;
        for (int i = 0; i < n-1; ++i) {
            double dx = -y/hypot(x, y), dy = x/hypot(x, y);
            x += dx;
            y += dy;
        }
        printf("%.10lf\n%.10lf\n", x, y);
    }
    return 0;
}