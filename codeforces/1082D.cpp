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
    vector<int> v(n);
    vector<pair<int, int>> vv(n);
    for (auto &&i : v) scanf("%d", &i);
    for (int i = 0; i < n; ++i) {
        vv[i] = make_pair(v[i], i+1);
    }
    sort(vv.begin(), vv.end());
    deque<pair<int, int>> d;
    for (int i = 0; i < n; ++i) {

    }
    return 0;
}
