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
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        double X = b * log10(a);
        double a3 = floor(X);
        X -= a3;
        X = exp10(X);
        double a1 = floor(X);
        X -= a1;
        double a2 = floor(X*10);
        printf("%.0f %.0f %.0f\n", a1, a2, a3);
    }
    return 0;
}