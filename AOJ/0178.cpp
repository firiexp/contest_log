#include <iostream>
#include <algorithm>
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

void solve(int n){
    vector<vector<int>> grid(5, vector<int>(5*n+1));
    for (int i = 0; i < 5; ++i) grid[i].back() = n+1;
    vector<int> alive(5*n+1);
    vector<int> cnt(5*n+1);
    iota(alive.begin(),alive.end(), 0);
    stack<int> X;
    for (int _ = 0; _ < n; ++_) {
        int d, p, q;
        cin >> d >> p >> q; q--;
        if(d == 1){
            for (int i = 1; i < grid[0].size(); ++i) {
                int ok = 1;
                for (int j = q; j < q+p; ++j) {
                    if(grid[j][alive[i]]) ok = 0;
                }
                if(!ok){
                    for (int j = q; j < q+p; ++j) {
                        int a = alive[i-1];
                        grid[j][a] = _+1;
                        cnt[a]++;
                        if(cnt[a] == 5) X.emplace(a);
                    }
                    break;
                }
            }
        }else {
            for (int i = 1; i+p-1 < grid[0].size(); ++i) {
                int ok = 1;
                for (int j = i; j < i+p; ++j) {
                    if(grid[q][alive[j]]) ok = 0;
                }
                if(!ok){
                    for (int j = i; j < i+p; ++j) {
                        int a = alive[j-1];
                        grid[q][a] = _+1;
                        cnt[a]++;
                        if(cnt[a] == 5) X.emplace(a);
                    }
                    break;
                }
            }
        }
        while(!X.empty()){
            alive.erase(lower_bound(alive.begin(),alive.end(), X.top())); X.pop();
        }
    }
    int ans = 0;
    for (auto &&j : alive) {
        for (int i = 0; i < 5; ++i) {
            if(grid[i][j] && grid[i][j] <= n) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}