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
    ll n, d, t;
    cin >> n >> d >> t;
    vector<int> v(n);
    for (auto &&k : v) scanf("%d", &k);
    vector<int> used(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(!used[i]){
            vector<pair<ll, ll>> a;
            for (int j = i; j < n; ++j) {
                if(!used[j] && (v[i]%d+d)%d == (v[j]%d+d)%d){
                    used[j] = 1;
                    a.emplace_back(v[j]-t*d, v[j]+(t+1)*d);
                }
            }
            sort(a.begin(),a.end());
            int cur = 0;
            while(cur < a.size()){
                int curr = cur + 1;
                while(curr < a.size() && a[curr].first <= a[cur].second){
                    a[cur].second = a[curr].second;
                    curr++;
                }
                ans += (a[cur].second-a[cur].first)/d;
                cur = curr;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}