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
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ok = 0, ng = n+1;
    vector<ll> v2(n);
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        for (ll i = 0; i < n; ++i) {
            v2[i] = v[i] + (i+1)*mid;
        }
        sort(v2.begin(),v2.end());
        ll S = 0;
        for (int i = 0; i < mid; ++i) {
            S += v2[i];
        }
        if(S <= s) ok = mid;
        else ng = mid;
    }
    for (ll i = 0; i < n; ++i) {
        v2[i] = v[i] + (i+1)*ok;
    }
    sort(v2.begin(),v2.end());
    ll S = 0;
    for (int i = 0; i < ok; ++i) {
        S += v2[i];
    }
    cout << ok << " " << S << "\n";
    return 0;
}