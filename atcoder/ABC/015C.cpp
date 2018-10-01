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
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        m[p]++;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < k; ++j) {
            int p;
            cin >> p;
            for (auto &&a : m) {
                m[(a.first^p)]++;
            }
        }
    }
    cout << (m[0] ? "Found\n" : "Nothing\n");
    return 0;
}
