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
    ll a, b;
    cin >> a >> b;
    cout << a/b << ".";
    a %= b;
    for (int i = 0; i < 50; ++i) {
        a *= 10;
        cout << a/b;
        a %= b;
    }
    puts("");
    return 0;
}