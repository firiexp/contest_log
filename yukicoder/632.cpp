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
    string s[3], t = "14";
    for (auto &&j : s) cin >> j;
    for (auto &i : s) {
        if(i == "?"){
            for (auto &&j : t) {
                int p = 0;
                i[0] = j;
                if(s[0] < s[1] && s[1] > s[2]) p = 1;
                if(s[0] > s[1] && s[1] < s[2]) p = 1;
                if(p) cout << j;
            }
        }
    }
    cout << "\n";
    return 0;
}
