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
    int h, a, d;
    cin >> h >> a >> d;
    int x = (h+a-1)/a*2;
    int ans = x;
    for (int i = 0; i < x/2; ++i) {
        ans = min(ans, i*2+(h-i*a+d-1)/d*3);
    }
    cout << 0.5*ans << "\n";
    return 0;
}