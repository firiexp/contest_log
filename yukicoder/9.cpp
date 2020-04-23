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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(2*n);
    for (auto &&i : a) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        b[i+n] = b[i];
    }
    using P = pair<int, int>;

    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        GPQ<P> Q;
        for (int j = 0; j < n; ++j) {
            Q.emplace(a[j], 0);
        }
        for (int k = 0; k < n; ++k) {
            auto p = Q.top(); Q.pop();
            p.first += b[i+k]/2;
            p.second++;
            Q.emplace(p);
        }
        int w = 0;
        while(!Q.empty()){
            w = max(w, Q.top().second); Q.pop();
        }
        ans = min(ans, w);
    }
    cout << ans << "\n";
    return 0;
}