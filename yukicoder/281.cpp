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

bool IsKadomatsu(int a, int b, int c){
    if(a == b || b == c || c == a) return false;
    return max({a, b, c}) == b || min({a, b, c}) == b;
}

int main() {
    ll d, a, b, c;
    cin >> d >> a >> b >> c;
    ll ans = INF<ll>, val = 0;
    if(a == c){
        a = max(a-d, 0LL);
        val++;
    }
    if(IsKadomatsu(a, b, c)) {
        cout << val << "\n";
    } else if(d == 0) {
        puts("-1");
    } else if(max({a, b, c}) == a + b + c) {
        puts("-1");
    }else {
        if(a > c) swap(a, c);
        if(a != 0){
            ans = min(ans, val + (b-a+d)/d);
        }
        if(b != 0){
            ll cc = max(0LL, c - (c-b+d)/d*d);
            if(IsKadomatsu(a, b, cc)){
                ans = min(ans, val + (c-b+d)/d);
            }
        }
        cout << (ans == INF<ll> ? -1 : ans) << "\n";
    }

    return 0;
}