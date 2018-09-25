#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    int p = b-a, q = c-b, ans = 0;
    if((a|b|c)&1){
        cout << 0 << "\n";
        return 0;
    }
    if(p == 0 && q == 0){
        cout << -1 << "\n";
        return 0;
    }
    else if(p == 0){
        p = q;
    }else if(q == 0){
        q = p;
    }
    p = __gcd(p, q);
    while(p%2 == 0){
        p/=2;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
