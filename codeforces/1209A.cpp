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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    int ans = 0;
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        if(used[i]) continue;
        used[i] = 1; ans++;
        for (int j = i+1; j < n; ++j) {
            if(__gcd(v[i], v[j]) == v[i]) used[j] = 1;
        }
    }
    cout << ans << "\n";
    return 0;
}