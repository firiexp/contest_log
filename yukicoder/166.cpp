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
    ll h, w, n, k;
    cin >> h >> w >> n >> k;
    if(h*w%n == k%n) puts("YES");
    else puts("NO");
    return 0;
}
