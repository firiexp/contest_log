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
    if(b < a) swap(a, b);
    if(c < b) swap(b, c);
    if(b < a) swap(a, b);
    int ans = 0;
    ans += c-b, a += c-b; b = c;
    if((c-a)%2) ans += (c-a)/2+2;
    else ans += (c-a)/2;
    cout << ans << "\n";
    return 0;
}
