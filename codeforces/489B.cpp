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
    int n, m;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    cin >> m;
    map<int, int> u;
    for (int i = 0; i < m; ++i) {
        int a; scanf("%d", &a);
        u[a]++;
    }
    int ans = 0;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(u[v[i]+j]) {
                ans++;
                u[v[i]+j]--;
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}