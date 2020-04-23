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
    ll h;
    cin >> h;
    auto rec = [&](ll x, auto &&f) -> ll{
        if(x == 0) return 0;
        return 2*f(x/2, f)+1;
    };
    cout << rec(h, rec) << "\n";
    return 0;
}