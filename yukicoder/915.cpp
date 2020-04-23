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
    int q;
    cin >> q;
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
        if(c == 1){
            cout << -1 << "\n";
            continue;
        }
        ll ans = INF<ll>, s = 0;
        while(a){
            ans = min(ans, s+(a+c-2)/(c-1)*b);
            if(a%c == 0) a /= c;
            else {
                a = a/c*c;
            }
            s += b;
        }
        cout << min(ans, s) << "\n";
    }
    return 0;
}