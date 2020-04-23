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
    int n;
    cin >> n;
    ll s = 0;
    vector<ll> v(n), movable(n, 1);
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lg", &x);
        double y = std::floor(x);
        if(x == y){
            movable[i] = 0;
        }
        v[i] = y;
        s += v[i];
        cnt += movable[i];
    }
    for (int i = 0; i < n; ++i) {
        if(movable[i] && s < 0) v[i]++, s++;
        printf("%lli\n", v[i]);
    }
    return 0;
}