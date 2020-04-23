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
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int>>> upper(n), lower(n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int a, b; string s;
            cin >> a >> s >> b;
            a--;
            if(s == ">=") lower[a].emplace_back(b, i);
            else upper[a].emplace_back(b, i);
        }
    }
    vector<vector<int>> G(m);
    vector<int> in(m);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : upper[i]) {
            for (auto &&k : lower[i]) {
                if(j.first < k.first){
                    G[j.second].emplace_back(k.second);
                    in[k.second]++;
                }
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        if(!in[i]) q.emplace(i);
    }
    while(!q.empty()){
        int i = q.front(); q.pop();
        for (auto &&j : G[i]) {
            in[j]--;
            if(!in[j]) q.emplace(j);
        }
        G[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        if(in[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}