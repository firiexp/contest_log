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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i+1;
    }
    int now = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < n; ++j) {
            if(v[j] == x) swap(now, v[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << "\n";
    }
    return 0;
}
