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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<bool> win(k+1, false);
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i < n; ++i) {
            if(j >= v[i]) win[j] = win[j] | (!win[j-v[i]]);
        }
    }
    cout << (win[k] ? "First" : "Second") << "\n";
    return 0;
}
