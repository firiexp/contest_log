#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    int sum = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x; m = max(m, x);
    }
    cout << sum << "\n";
    cout << max(0, 2*m-sum) << "\n";
    return 0;
}
