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
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m[(int)s.size()-2]++;
    }
    vector<pair<int, int>> v;
    v.reserve(m.size());
    for (auto &&i : m) {
        v.emplace_back(-i.second, -i.first);
    }
    sort(v.begin(), v.end());
    cout << -v[0].second << "\n";
    return 0;
}
