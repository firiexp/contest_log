#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v1[i]);
        v2[i] = v1[i];
    }
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; ++i) {
        printf("%li\n", n+1-(upper_bound(v2.begin(), v2.end(), v1[i]) - v2.begin()));
    }
    return 0;
}
