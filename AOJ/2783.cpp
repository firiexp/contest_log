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
    ll x;
    cin >> x;
    vector<ll> ans;
    ll ok = 0, ng = 100000;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        if(mid*(mid-1)/2 < x) ok = mid;
        else ng = mid;
    }
    string s = string(ok, ')')+string(ok, '(');
    x = ok*(ok+1)/2-x;
    int cur = ok;
    for (int i = 0; i < x; ++i) {
        swap(s[cur-1], s[cur]);
        cur--;
    }
    cout << s << "\n";
    return 0;
}