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
    map<int, int> m;
    ll ans = 0;
    string s;
    cin >> s;
    int depth = 0;
    for (auto &&i : s) {
        if(i == '('){
            m[depth]++;
            depth++;
        }else {
            m[depth] = 0;
            depth--;
            ans += m[depth];
        }
    }
    cout << ans << "\n";
    return 0;
}
