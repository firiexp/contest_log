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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, k;
    cin >> n >> k;
    using P = array<int, 3>;
    vector<vector<P>> v(100001);
    for (int i = 0; i < n; ++i) {
        int s, p, u;
        cin >> s >> p >> u;
        v[u].emplace_back(P{s, -p, i});
    }
    priority_queue<tuple<int, int, int, int>> Q;
    for (int i = 0; i < 100001; ++i) {
        if(!v[i].empty()){
            sort(v[i].begin(),v[i].end());
            Q.emplace(v[i].back()[0], 0, v[i].back()[1], i);
        }
    }
    for (int i = 0; i < k; ++i) {
        int s, num, p, id; tie(s, num, p, id) = Q.top(); Q.pop();
        printf("%d\n", v[id].back()[2]);
        v[id].pop_back();
        if(!v[id].empty()){
            Q.emplace(v[id].back()[0], num-1, v[id].back()[1], id);
        }
    }
    return 0;
}