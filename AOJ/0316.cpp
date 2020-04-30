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
    int h1, h2, k1, k2, a, b, c, d;
    cin >> h1 >> h2 >> k1 >> k2 >> a >> b >> c >> d;
    auto f = [&](int p, int q){ return p*a+q*b+p/10*c+q/20*d; };
    if(f(h1, h2) < f(k1, k2)) puts("kenjiro");
    else if(f(h1, h2) > f(k1, k2)) puts("hiroshi");
    else puts("even");
    return 0;
}