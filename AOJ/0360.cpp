#include <iostream>
#include <algorithm>
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
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;
        if(max(a, c) < min(b, d)) {
            puts("1");
            return 0;
        }
    }
    puts("0");
    return 0;
}