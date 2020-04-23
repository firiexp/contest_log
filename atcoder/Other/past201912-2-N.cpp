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
    int n, w, c;
    cin >> n >> w >> c;
    vector<int> ps;
    ps.emplace_back(0);
    ps.emplace_back(w-c);
    using P = array<int, 3>;
    vector<array<int, 3>> q(2*n);
    for (int i = 0; i < n; ++i) {
        int l, r, p;
        cin >> l >> r >> p;
        ps.emplace_back(l);
        ps.emplace_back(r);
        q[2*i] = {l-c+1, i, p};
        q[2*i+1] = {r, i, p};
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    sort(q.begin(),q.end());
    ll ans = INF<ll>, val = 0, cur = 0;
    set<pair<int, int>> s;
    for (auto &&i : ps) {
        while(cur < q.size() && q[cur][0] <= i){
            if(s.count({q[cur][1], q[cur][2]})){
                val -= q[cur][2];
                s.erase({q[cur][1], q[cur][2]});
            }else {
                val += q[cur][2];
                s.emplace(q[cur][1], q[cur][2]);
            }
            cur++;
        }
        ans = min(ans, val);
        if(i == w-c) break;
    }
    cout << ans << "\n";
    return 0;
}