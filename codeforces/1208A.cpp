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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, n;
        cin >> a >> b >> n;
        if(n%3 == 0) cout << a << "\n";
        else if(n%3 == 1) cout << b << "\n";
        else cout << (a^b) << "\n";
    }
    return 0;
}