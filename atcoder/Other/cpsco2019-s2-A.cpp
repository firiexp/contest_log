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
    int m, n;
    cin >> m >> n;
    int mm = m;
    for (int i = 0; i < n-1; ++i) {
        mm -= m/n;
    }
    cout << mm << "\n";
    return 0;
}