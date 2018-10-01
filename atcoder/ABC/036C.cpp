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
    vector<int> v, v2;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v.emplace_back(x);
        v2.emplace_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        cout << lower_bound(v.begin(), v.end(), v2[i]) - v.begin() << "\n";
    }
    return 0;
}
