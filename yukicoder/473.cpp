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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n, x;
    cin >> n >> x;
    x++;
    int ans = 0;
    auto v = divisor(x);
    int m = v.size();
    vector<vector<int>> divisors(m);
    for (int i = 0; i < m; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if(v[i]%v[j] == 0) divisors[i].emplace_back(j);
        }
    }
    auto dfs = [&](int x, int dep, int ub, auto &&f) -> void {
        if(x == 0) {
            if(dep == n) ans++;
            return;
        }
        for (auto &&i : divisors[x]) {
            if(ub < v[x]/v[i]) return;
            f(i, dep+1, v[x]/v[i], f);
        }
    };
    dfs(m-1, 0, x, dfs);
    cout << ans << "\n";
    return 0;
}