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
    vector<string> v(n);
    map<string, int> m;
    int x = 0;
    for (auto &&i : v) {
        cin >> i;
        m[i]++;
        x = max(x, m[i]);
    }
    for (auto &&j : m) {
        if(j.second == x) cout << j.first << "\n";
    }
    return 0;
}