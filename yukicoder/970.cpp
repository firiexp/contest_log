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
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i *= (n-1);
    ll x = accumulate(v.begin(),v.end(), 0LL)/(n-1);
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", x-v[i]);
    }

    puts("");
    return 0;
}