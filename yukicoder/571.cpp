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
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < 3; ++i) {
        int h, w;
        cin >> h >> w;
        v.emplace_back(-h, w, i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; ++i) {
        cout << char('A'+get<2>(v[i])) << "\n";
    }
    return 0;
}
