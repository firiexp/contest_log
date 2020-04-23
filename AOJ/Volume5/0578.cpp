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
    string s;
    cin >> n >> s;
    int ans = 0;
    auto S = s.size();
    for (int i = 0; i < n; ++i) {
        int c = 0;
        string t;
        cin >> t;
        for (int j = 0; S+(S-1)*j <= t.length(); ++j) {
            for (int k = 0; k < t.length()-S-(S-1)*j+1; ++k) {
                int x = 1;
                for (int l = 0; l < S; ++l) {
                    if(s[l] != t[k+(j+1)*l]) x = 0;
                }
                c |= x;
            }
        }
        ans += c;
    }
    cout << ans << "\n";
    return 0;
}
