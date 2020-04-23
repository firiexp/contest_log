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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i+j <= n; ++j) {
            string t = s.substr(i, j);
            int valid = 1;
            for (int k = 0; k < j; ++k) {
                if(t[k] != 'A' && t[k] != 'T' && t[k] != 'G' && t[k] != 'C') valid = 0;
            }
            if(valid) ans = max(ans, j);
        }
    }
    cout << ans << "\n";
    return 0;
}
