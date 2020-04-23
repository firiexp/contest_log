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
    ll n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n);
    for (int i = 0; i < k; ++i) {
        ans[i] = s;
    }
    for (int i = k; i < n; ++i) {
        if(s != 1000000000) ans[i] = 1000000000;
        else ans[i] = 999999999;
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}