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
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (auto &&i : p) scanf("%d", &i);
    for (auto &&j : q) scanf("%d", &j);
    for (auto &&k : r) scanf("%d", &k);
    sort(p.begin(),p.end(), greater<>());
    sort(q.begin(),q.end(), greater<>());
    sort(r.begin(),r.end(), greater<>());
    ll S = 0;
    GPQ<int> Q;
    for (int i = 0; i < x; ++i) {
        S += p[i];
        Q.emplace(p[i]);
    }
    for (int i = 0; i < y; ++i) {
        S += q[i];
        Q.emplace(q[i]);
    }
    ll ans = S;
    for (int i = 0; i < min(c, x+y); ++i) {
        S -= Q.top(); Q.pop();
        S += r[i];
        ans = max(ans, S);
    }
    cout << ans << "\n";
    return 0;
}