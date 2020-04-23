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
    int a, b, s;
    cin >> a >> b >> s;
    int ans = 0;
    if(abs(s-a) <= abs(s-b) || s == 1) ans = abs(s-a) + s;
    else if(a != 0) ans = a + abs(s-b) + min(s-1, abs(s-a));
    else ans = abs(s-b) + s+1;
    printf("%d\n", ans);
    return 0;
}
