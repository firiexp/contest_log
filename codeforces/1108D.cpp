#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t = "RGB";
    s = "?" + s + "?";
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if(s[i-1] == s[i]){
            for (int j = 0; j < 3; ++j) {
                if(s[i-1] != t[j] && s[i+1] != t[j]) {
                    s[i] = t[j];
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    cout << s.substr(1, n) << "\n";
    return 0;
}
