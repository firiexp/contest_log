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
    string s, t, p1, p2, x1, x2;
    cin >> s >> p1 >> x1;
    cin >> t >> p2 >> x2;
    array<int, 10010> v{}, v2{};
    for (int i = 0; i < p1.size(); ++i) {
        v[10010-p1.size()+i] = p1[i] - '0';
    }
    for (int i = 0; i < p2.size(); ++i) {
        v2[10010-p2.size()+i] = p2[i] - '0';
    }
    if(v > v2) cout << s << "\n";
    else if (v < v2) cout << t << "\n";
    else cout << -1 << "\n";
    return 0;
}
