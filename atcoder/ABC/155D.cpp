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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &&i : v) scanf("%lld", &i);
    sort(v.begin(),v.end());
    ll ng = -INF<ll>, ok = INF<ll>;
    while(ok-ng > 1){
        ll mid = ng+(ok-ng)/2;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] > 0){
                ll ok2 = -1, ng2 = n;
                while(ng2 - ok2 > 1){
                    ll mid2 = (ok2+ng2)/2;
                    (v[i]*v[mid2] <= mid ? ok2 : ng2) = mid2;
                }
                cnt += ok2+1;
            }else if(v[i] == 0){
                cnt += (mid >= 0 ? n : 0);
            }else {
                ll ok2 = n, ng2 = -1;
                while(ok2 - ng2 > 1){
                    ll mid2 = (ok2+ng2)/2;
                    (v[i]*v[mid2] <= mid ? ok2 : ng2) = mid2;
                }
                cnt += n-ok2;
            }
            cnt -= v[i]*v[i] <= mid;
        }
        (cnt/2 < k ? ng : ok) = mid;
    }
    cout << ok << "\n";
    return 0;
}