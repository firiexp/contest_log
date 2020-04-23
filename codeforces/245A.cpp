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
    int n;
    cin >> n;
    int x = 0, X = 0, y = 0, Y = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) x += b, X += 10;
        else y += b, Y += 10;
    }
    puts(x*2 < X ? "DEAD" : "LIVE");
    puts(y*2 < Y ? "DEAD" : "LIVE");
    return 0;
}