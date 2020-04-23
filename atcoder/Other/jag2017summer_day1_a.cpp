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
    ll n;
    cin >> n;
    if(n <= 52){
        cout << n/2*3+(n%2) << "\n";
    }else {
        int x = 1; ll a = 26, ans = 0;
        while(n){
            ll p = min(a, n);
            ans += x*p;
            n -= p;
            a *= 26;
            x++;
        }
        cout << ans << "\n";
    }
    return 0;
}