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
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].second = i+1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a-1].first += c; v[b-1].first -= c;
    }
    int cur1 = 0, cur2 = n-1;
    sort(v.begin(),v.end());
    vector<tuple<int, int, ll>> ans;
    while(cur1 < cur2){
        if(v[cur1].first < 0 && v[cur2].first > 0){
            ll val = min(-v[cur1].first, v[cur2].first);
            ans.emplace_back(v[cur2].second, v[cur1].second, val);
            v[cur1].first += val;
            v[cur2].first -= val;
        }
        if(v[cur1].first >= 0) cur1++;
        if(v[cur2].first <= 0) cur2--;
    }
    printf("%zu\n", ans.size());
    for (auto &&i : ans) {
        int a, b; ll c;
        tie(a, b, c) = i;
        printf("%d %d %lld\n", a, b, c);
    }
    return 0;
}