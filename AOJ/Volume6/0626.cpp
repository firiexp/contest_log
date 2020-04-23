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
    int n; string s;
    cin >> n >> s;
    ll ans = 0, j = 0, jo = 0, joi = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'J') j++;
        else if(s[i] == 'O') jo += j;
        else joi += jo;
    }
    ans = joi; ans2 = jo;
    vector<ll> J(n);
    J[0] = s[0] == 'J';
    for (int i = 1; i < n; ++i) {
        J[i] = J[i-1]+ (s[i] == 'J');
    }
    ll I = 0, IO = 0;
    for (int i = n-1; i >= 0; --i) {
        if(s[i] == 'I') I++;
        else if(s[i] == 'O') IO += I;
        ans2 = max(ans2, I*J[i]);
    }
    ans2 = max(ans2, IO);


    cout << ans+ans2 << "\n";
    return 0;
}
