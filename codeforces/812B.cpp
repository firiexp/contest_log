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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> l(n, m+1), r(n, 0);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < m+2; ++j) {
            if(v[i][j] == '1') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
                cnt[i]++;
            }
        }
    }
    reverse(v.begin(),v.end());
    reverse(l.begin(),l.end());
    reverse(r.begin(),r.end());
    reverse(cnt.begin(),cnt.end());
    vector<int> dp1(n, INF<int>), dp2(n, INF<int>);
    ll c = accumulate(cnt.begin(),cnt.end(), 0);
    dp1[0] = 0;
    for (int i = 0; i < n; ++i) {
        c -= cnt[i];
        if(!c){
            cout << min(dp1[i]+r[i], dp2[i]+(m+1-l[i]))+i << "\n";
            return 0;
        }
        dp1[i+1] = min(dp1[i]+2*r[i], dp2[i]+m+1);
        dp2[i+1] = min(dp1[i]+m+1, dp2[i]+2*(m+1-l[i]));
    }

    return 0;
}