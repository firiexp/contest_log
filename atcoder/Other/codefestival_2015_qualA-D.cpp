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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for (auto &&i : v) scanf("%li", &i);
    ll ng = -1, ok = 2*n+1;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        if(mid < v[0] -1){
            ng = mid;
            continue;
        }
        ll y = 0;
        for (int i = 0; i < m; ++i) {
            if(y+mid+1 < v[i]){
                y = -1;
                break;
            }else if(y+1 < v[i]){
                y = max({v[i], y+mid-(v[i]-y-2), v[i] + (y+mid-v[i]+1)/2});
            }else {
                y = v[i]+mid;
            }
        }
        (y >= n ? ok : ng) =  mid;
    }
    cout << ok << "\n";
    return 0;
}
