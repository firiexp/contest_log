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
    int n, k;
    cin >> n >> k;
    vector<int> r(200001, -INF<int>), cnt(200001);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        v[i]--;
        cnt[v[i]]++;
        r[v[i]] = max(r[v[i]], i);
    }
    sort(r.begin(),r.end());
    int a = 0, b = 0, S = 0, ans = 0;
    int cur = lower_bound(r.begin(),r.end(), 0) - r.begin();
    for (int i = 0; i < n; ++i) {
        while(cur < 200001 && r[cur] == i){
            a = max(a, cnt[v[i]]);
            S += cnt[v[i]];
            b += cnt[v[i]];
            cur++;
        }
        if(S == i+1){
            ans += b-a;
            a = 0;
            b = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}