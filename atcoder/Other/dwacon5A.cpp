#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<long double> v(n);
    long double ans = 0, q = 2092358918732;
    for (auto &&i : v) {
        scanf("%Lf", &i);
        ans += i;
    }
    ans /= n;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if(fabs(ans-v[i]) < q) k = i, q = fabs(ans-v[i]);
    }
    cout << k << "\n";
    return 0;
}
