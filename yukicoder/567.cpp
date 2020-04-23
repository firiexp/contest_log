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
    double ans = 1;
    vector<double> t{1, 6, 15, 20, 15, 6, 1};
    for (int i = 1; i <= 6; ++i) {
        double k = pow(1-i/6.0, n)*t[i];
        ans += (i%2 ? -k : k);
    }
    printf("%.15f\n", ans);
    return 0;
}