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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        if(v[i] < 0) v[i] = -v[i];
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    int l = 0, r = 0;
    while(r < n){
        r++;
        while(l < r && 2*v[l] < v[r-1]) l++;
        if(r != l) ans += r-l-1;
    }
    cout << ans << "\n";
    return 0;
}