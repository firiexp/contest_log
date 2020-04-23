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
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    vector<ll> ans(n);
    ans[0] = accumulate(v.begin(),v.end(), 0LL);
    for (int j = 1; j < n; j += 2) {
        ans[0] -= 2*v[j];
    }
    for (int j = 1; j < n; ++j) {
        ans[j] = 2*v[j-1]-ans[j-1];
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%lld", ans[i]);
    }
    puts("");
    return 0;
}