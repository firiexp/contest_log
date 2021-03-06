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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

vector<ll> divisor(ll n){
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    ll a, b;
    cin >> a >> b;
    auto v = divisor(a+b);
    for (auto &&c : v) {
        if(a == c || b == c) continue;

        if((a+b)%c == 0 && (b+c)%a == 0 && (c+a)%b == 0){
            printf("%lli\n", c);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
