#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    u32 n, m, k;
    cin >> n >> m >> k;
    if(k <= m) {
        puts("-1");
        return 0;
    }
    k -= m;
    int r = 0;
    vector<int> ans, e(n, 0), dis(n);
    vector<vector<int>> child(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 0) r = i;
        else {
            child[x-1].emplace_back(i);
        }
    }
    stack<pair<int, int>> s;
    s.emplace(r, 0);
    while (!s.empty()){
        auto x = s.top(); s.pop();
        dis[x.first] = x.second;
        for (auto &&i : child[x.first]) s.emplace(i, x.second+1);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(e[j]) continue;
            vector<int> e2 = e;
            stack<int> ss;
            ss.emplace(j);
            while(!ss.empty()) {
                auto y = ss.top(); ss.pop();
                e2[y] = 1;
                for (auto &&x : child[y]) if(!e2[x]) ss.emplace(x);

            }
            vector<int> t;
            int smin = 0, smax = 0;
            for (int l = 0; l < n; ++l) if(!e2[l]) t.emplace_back(dis[l]);
            if(t.size() < m-i-1) continue;
            sort(t.begin(), t.end());
            for (int l = 0; l < m-i-1; ++l) {
                smin += t[l];
                smax += t[t.size()-l-1];
            }
            if(smin+dis[j] <= k && k <= smax+dis[j]){
                k -= dis[j];
                ans.emplace_back(j);
                e = e2;
                break;
            }
        }
        if(ans.size() < i+1) {
            puts("-1");
            return 0;
        }
    }
    for (auto &&i : ans) printf("%d ", i+1);
    return 0;
}
