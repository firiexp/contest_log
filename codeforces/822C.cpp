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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, x;
    cin >> n >> x;
    using P = array<int, 3>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &v[i][j]);
        }
        v[i][1]++;
    }
    auto v2 = v;
    sort(v.begin(),v.end(), [&](P a, P b){return a[0] < b[0];});
    sort(v2.begin(),v2.end(), [&](P a, P b){ return a[1] < b[1]; });
    int ans = 2000000001, cur = 0;
    vector<int> val(200001, INF<int>);
    for (int i = 0; i < n; ++i) {
        if(v[i][1]-v[i][0] >= x) continue;
        while(cur < n && v2[cur][1] <= v[i][0]) {
            chmin(val[v2[cur][1]-v2[cur][0]], v2[cur][2]);
            cur++;
        }
        if(val[x-(v[i][1]-v[i][0])] == INF<int>) continue;
        chmin(ans, v[i][2]+val[x-(v[i][1]-v[i][0])]);
    }
    cout << (ans == 2000000001 ? -1 : ans) << "\n";
    return 0;
}