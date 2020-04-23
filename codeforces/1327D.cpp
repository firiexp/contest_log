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

vector<vector<int>> divisor(200001);

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (auto &&i : p) scanf("%d", &i), i--;
    vector<int> c(n);
    for (auto &&i : c) scanf("%d", &i), i--;
    vector<int> cnt(n);
    vector<vector<int>> v;

    int ans = INF<int>;
    for (int i = 0; i < n; ++i) {
        int x = p[i];
        if(cnt[i]) continue;
        v.emplace_back();
        v.back().emplace_back(i);
        cnt[i] = 1;
        while(x != i){
            v.back().emplace_back(x);
            cnt[x] = 1;
            x = p[x];
        }
        ans = min(ans, (int)v.back().size());
    }
    for (auto &&a : v) {
        for (auto &&d : divisor[a.size()]) {
            if(d >= ans) continue;
            for (int i = 0; i < d; ++i) {
                int ok = 1, col = c[a[i]];
                for (int j = i+d; j < a.size(); j += d) {
                    if(c[a[j]] != col) {
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    ans = d;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    for (int i = 1; i <= 200000; ++i) {
        for (int j = i+i; j <= 200000; j += i) {
            divisor[j].emplace_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}