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

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> u;
    for (int i = 0; i+1 < n; ++i) {
        if((v[i] < 0 && v[i+1] >= 0)){
            u.emplace_back(v[i+1]);
        }else if(v[i] >= 0 && v[i+1] < 0) {
            u.emplace_back(v[i]);
        }
    }
    sort(u.begin(),u.end());
    int x = 0;
    if(!u.empty()){
        x = (u.back()+u.front())/2;
    }
    for (int i = 0; i < n; ++i) {
        if(v[i] == -1) v[i] = x;
    }
    ll ans = 0;
    for (int i = 0; i+1 < n; ++i) {
        ans = max<ll>(ans, abs(v[i]-v[i+1]));
    }
    printf("%lld %d\n", ans, x);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}