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
    string s, t;
    while (cin >> s >> t){
        int ans = 0;
        for (int i = -(int)s.length(); i <= (int)t.length(); ++i) {
            int l = 0;
            for (int j = max(i, 0); j < min(s.length()+i, t.length()); ++j) {
                if(s[j-i] == t[j]){
                    l++;
                    ans = max(ans, l);
                } else l = 0;
            }

        }
        cout << ans << "\n";
    }
    return 0;
}
