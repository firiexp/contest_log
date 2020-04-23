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
    using P = pair<int, char>;
    vector<P> v(3);
    int a, b, c;
    cin >> a >> b >> c;
    v[0] = {a, 'A'};
    v[1] = {b, 'B'};
    v[2] = {c, 'C'};
    sort(v.begin(), v.end(), greater<>());
    for (auto &&i : v) {
        cout << i.second << "\n";
    }
    return 0;
}
