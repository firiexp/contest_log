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
    string s;
    cin >> s;
    ll n = stoll(s);
    ll x = 1;
    for (char i : s) {
        x *= 10;
    }
    string t = "0123456789";
    ll ans = INF<ll>, diff = 0;
    do {
        ll u = stoll(t.substr(0, s.size()));
        if(diff < min(x-abs(u-n), abs(u-n))){
            diff = min(x-abs(u-n), abs(u-n));
            ans = u;
        }else if(diff == min(x-abs(u-n), abs(u-n))){
            ans = min(ans, u);
        }
    }while(next_permutation(t.begin(),t.end()));
    string y = to_string(ans);
    while(s.size() > y.size()) y = "0" + y;
    cout << y << "\n";
    return 0;
}