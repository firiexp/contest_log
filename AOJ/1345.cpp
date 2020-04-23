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

int solve(vector<int> v, vector<int> u){
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i] != u[i]){
            int x = -1;
            for (int j = n-1; j >= i+1; --j) {
                if(v[j] == u[i]) x = j;
            }
            if(x == -1) return INF<int>;
            for (int k = x-1; k >= i; --k) {
                swap(v[k], v[k+1]);
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n), u(n);
    for (auto &&i : v) scanf("%d", &i);
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        while(x--){
            u[cur++] = i&1;
        }
    }
    int ans = solve(v, u);
    for (int i = 0; i < n; ++i) {
        u[i] ^= 1;
    }
    ans = min(ans, solve(v, u));
    cout << ans << "\n";
    return 0;
}