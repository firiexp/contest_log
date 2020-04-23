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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> G(n);
    for (int i = 0; i < n-1; ++i) {
        int p;
        cin >> p;
        G[p-1].emplace_back(i+1);
    }
    vector<int> A, B;
    auto dfs = [&](int x, auto &&f) -> bool {
        bool parity = false;
        for (auto &&y : G[x]) parity = f(y, f)^1;
        (parity ? A : B).emplace_back(v[x]);
        return parity;
    };
    dfs(0, dfs);
    ll ans = 0;
    int a = 0;
    map<int, int> x;
    for (auto &&i : B) a ^= i, x[i]++;
    if(a){
        for (auto &&i : A) ans += x[a^i];
    }else {
        for (auto &&i : A) ans += x[a^i];
        int aa = A.size(), bb = B.size();
        ans += (ll)aa*(aa-1)/2;
        ans += (ll)bb*(bb-1)/2;
    }
    cout << ans << "\n";
    return 0;
}