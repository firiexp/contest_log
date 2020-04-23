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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int k, n;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    sort(v.begin(),v.end(), greater<>());
    ll a = INF<int>, b = 0, ans = 0;
    GPQ<int> Q;
    for (int i = 0; i < n; ++i) {
        a = min<ll>(a, v[i].first);
        Q.emplace(v[i].second);
        b += v[i].second;
        if(i >= k) b -= Q.top(), Q.pop();
        ans = max(ans, a*b);
    }
    cout << ans << "\n";
    return 0;
}