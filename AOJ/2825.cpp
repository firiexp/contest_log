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
    while(cin >> n >> m, n){
        vector<int> v(n), u(n);
        for (int i = 0; i < m; ++i) {
            int s, k;
            scanf("%d %d", &s, &k);
            if(k == 1){
                int x;
                scanf("%d", &x);
                v[x-1] += s;
            }else {
                for (int j = 0; j < k; ++j) {
                    int x;
                    scanf("%d", &x);
                    u[x-1] += s;
                }
            }
        }
        vector<int> vv(v);
        sort(vv.begin(),vv.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, v[i]+u[i]-(vv[0] == v[i] ? vv[1] : vv[0])+1);
        }
        cout << ans << "\n";
    }
    return 0;
}