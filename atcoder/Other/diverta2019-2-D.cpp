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

const int M = 30000000;
array<ll, M+10> dp{};

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n;
    cin >> n;
    array<array<int, 5>, 5> v{};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        dp[i] = -INF<ll>;
    }
    dp[n] = n;
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            if(v[0][j] < v[1][j]){
                ll b = v[1][j] - v[0][j], c = v[0][j];
                if(i-c >= 0){
                    dp[i-c] = max(dp[i-c], dp[i]+b);
                }
            }
        }
    }
    ll V = 0;
    for (int i = 0; i <= n; ++i) {
        V = max(V, dp[i]);
    }
    for (int i = 0; i < M; ++i) {
        dp[i] = -INF<ll>;
    }
    dp[V] = V;
    for (int i = V; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) {
            if(v[1][j] < v[0][j]){
                ll b = v[0][j] - v[1][j], c = v[1][j];
                if(i-c >= 0){
                    dp[i-c] = max(dp[i-c], dp[i]+b);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= V; ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}