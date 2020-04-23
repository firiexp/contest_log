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
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
    }
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        int p = v[k-1];
        for (int j = k-2; j >= 0; --j) {
            v[j+1] = v[j];
        }
        v[0] = p;
    }
    cout << v[0] << "\n";
    return 0;
}
