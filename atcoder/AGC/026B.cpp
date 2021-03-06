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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > a){
            puts("No");
            continue;
        }else if(b > d){
            puts("No");
            continue;
        }else if(c >= b){
            puts("Yes");
            continue;
        }
        ll g = __gcd(b, d);
        ll q = b-c-g+a%g;
        puts(q <= 0 ? "Yes" : "No");
    }
    return 0;
}
