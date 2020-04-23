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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt2 = 0;
    for (int i = 0; i < 31; ++i) {
        int x = a & (1 << i), y = b & (1 << i);
        if(x && !y) {
            puts("0");
            return 0;
        }
        if(!x && y) cnt2++;
    }
    if(cnt2 == 0) puts("1");
    else cout << (1LL << (cnt2-1)) << "\n";
    return 0;
}