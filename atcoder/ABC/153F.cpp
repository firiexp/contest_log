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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    GPQ<tuple<ll, ll, ll>> Q;
    for (int i = 0; i < n; ++i) {
        Q.emplace(v[i].first, 0, i);
    }
    ll val = 0, ans = 0;
    while(!Q.empty()){
        int x, y, z;
        tie(x, y, z) = Q.top(); Q.pop();
        if(y){
            val -= z;
        }else {
            if(v[z].second > val){
                ll w = (v[z].second-val+a-1)/a;
                ans += w;
                Q.emplace(v[z].first+2*d, 1, w*a);
                val += w*a;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}