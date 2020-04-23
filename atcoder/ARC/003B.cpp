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
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        reverse(v[i].begin(), v[i].end());
        cout << v[i] << "\n";
    }

    return 0;
}
