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
    int n, k;
    cin >> n >> k;
    int dep = 0;
    vector<int> d(n-1);
    string s;
    cin >> s;
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == '(') dep++;
        else dep--;
        d[i] = dep;
    }
    sort(d.begin(),d.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += d[i];
    }
    cout << ans << "\n";
    return 0;
}