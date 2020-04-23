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
    int k;
    cin >> k;
    vector<int> v(k+1, 1);
    for (int i = 2; i <= k; ++i) {
        v[i] = v[i-1] + v[i-2];
    }
    cout << v[k-1] << " " << v[k] << "\n";
    return 0;
}
