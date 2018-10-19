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

int rev(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}

vector<vector<int>> v(1000, vector<int>(1000, 0));

int check(int x, int y){

    if(v[y][x]) return v[y][x];
    if(x*y == 0) return v[y][x] = 1;
    v[y][x] = 3;
    int x2 = x, y2 = y;

    if(x < y) x2 = rev(x2);
    else y2 = rev(y2);

    if(x2 < y2) y2 = y2 - x2;
    else x2 = x2-y2;
    int p = check(x2, y2);
    return v[y][x] = (p == 1 ? 1 : 2);
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(check(i, j) == 2) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
