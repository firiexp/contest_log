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
    int n;
    cin >> n;
    vector<int> v(n-1);
    for (auto &&i : v) scanf("%d", &i);
    vector<vector<int>> dp0(2, vector<int>(n/2+1, INF<int>)), dp1(2,vector<int>(n/2+1, INF<int>));
    dp0[0][0] = 0; dp1[0][1] = 0;
    for (int i = 0; i < n-1; ++i) {
        int now = i&1, nxt = now^1;
        fill(dp0[nxt].begin(),dp0[nxt].end(), INF<int>);
        fill(dp1[nxt].begin(),dp1[nxt].end(), INF<int>);
        for (int j = 0; j <= min(i+1, n/2); ++j) {
            dp0[nxt][j] = min({dp0[nxt][j], dp0[now][j], dp1[now][j]+v[i]});
            if(j < n/2) dp1[nxt][j+1] = min({dp1[nxt][j+1], dp0[now][j]+v[i], dp1[now][j]});
        }
    }
    cout << min(dp0[(n-1)&1][n/2], dp1[(n-1)&1][n/2]) << "\n";
    return 0;
}