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
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < min(i+1, n-i); ++j) {
            if(s[i+j] == s[i-j]) x += (j == 0 ? 1 : 2);
        }
        ans = max(ans, x);
    }
    for (int i = 0; i < n-1; ++i) {
        int x = 0;
        for (int j = 0; j < min(i+1, n-i-1); ++j) {
            if(s[i-j] == s[i+1+j]) x += 2;
        }
        ans = max(ans, x);
    }
    cout << ans << "\n";
    return 0;
}
