#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), u((n+1)*(n+2)/2);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+1]);
    }
    int id = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            u[id++] = v[i]+v[j];
        }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    int ans = 0, cur1 = 0, cur2 = id-2;
    while(cur1 <= cur2) {
        while(u[cur1]+u[cur2] > m) cur2--;
        chmax(ans, u[cur1]+u[cur2]);
        cur1++;
    }
    cout << ans << "\n";
    return 0;
}
