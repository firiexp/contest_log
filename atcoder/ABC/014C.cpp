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
    vector<int> v(1000002, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a]++;
        v[b+1]--;
    }
    int p = 0, q = 0;
    for (int i = 0; i <= 1000000; ++i) {
        p += v[i];
        q = max(p, q);
    }
    cout << q << "\n";
    return 0;
}
