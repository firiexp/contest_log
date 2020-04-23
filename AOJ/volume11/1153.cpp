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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    while(cin >> n >> m, n|m){
        vector<int> v(n), u(m);
        int s1 = 0, s2 = 0;
        for (auto &&i : v) scanf("%d", &i), s1 += i;
        for (auto &&j : u) scanf("%d", &j), s2 += j;
        int ans1 = INF<int>, ans2 = INF<int>;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(s1+u[j]-v[i] == s2 + v[i]-u[j]){
                    if(ans1 + ans2 > u[j] + v[i]){
                        ans1 = v[i], ans2 = u[j];
                    }
                }
            }
        }
        if(ans1 != INF<int>){
            cout << ans1 << " " << ans2 << "\n";
        } else puts("-1");

    }
    return 0;
}
