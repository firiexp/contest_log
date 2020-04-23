#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int q;
    cin >> q;
    string a = "good", b = "problem";
    for (int i = 0; i < q; ++i) {
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        int ans = 11;

        for (int j = 0; j < n-10; ++j) {
            int p = 0;
            for (int k = 0; k < 4; ++k) {
                if(a[k] != s[j+k]) p++;
            }
            for (int k = j+4; k < n-6; ++k) {
                int r = p;
                for (int l = 0; l < 7; ++l) {
                    if(b[l] != s[k+l]) r++;
                }
                ans = min(ans, r);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
