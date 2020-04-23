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

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    string s;
    cin >> s;
    ll ans = 1;
    ll p = 1;
    reverse(s.begin(),s.end());
    s[0]++;

    s += '0';
    int cur = 0;
    while(s[cur] == '2') {
        s[cur+1]++;
        s[cur] = '0';
        cur++;
    }
    if(s.back() == '0') s.pop_back();
    reverse(s.begin(),s.end());
    for (int i = 1; i < s.size(); ++i) {
        ans = (ans*3)%MOD;
        if(s[i] == '1'){
            (p *= 2) %= MOD;
            (ans += p) %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}