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
    int x;
    cin >> x;
    if(x == 3) puts("YES");
    else if(x == 5) puts("YES");
    else if(x == 7) puts("YES");
    else puts("NO");
    return 0;
}
