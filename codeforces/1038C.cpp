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
    vector<pair<int, int>> v(2*n);
    for (int i = 0; i < n; ++i) {
        v[i].second = 0;
        scanf("%d", &v[i].first);
    }
    for (int i = 0; i < n; ++i) {
        v[i+n].second = 1;
        scanf("%d", &v[i+n].first);
    }
    sort(v.begin(),v.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < 2*n; ++i) {
        if(i%2 == v[i].second){
            if(i&1) ans -= v[i].first;
            else ans += v[i].first;
        }
    }
    cout << ans << "\n";
    return 0;
}