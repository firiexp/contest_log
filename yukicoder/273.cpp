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

bool is_parindrome(const string s, char c = '?'){
    auto n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] == c || s[n-i-1] == c) continue;
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i+j <= n; ++j) {
            if(j == n) continue;
            if(is_parindrome(s.substr(i, j))) ans = max(ans, j);
        }
    }
    cout << ans << "\n";
    return 0;
}
