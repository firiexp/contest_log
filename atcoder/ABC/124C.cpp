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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        char a = '0', b = '1';
        if(i%2) swap(a, b);
        ans += a == s[i];
    }
    cout << min(ans, (int)s.size()-ans) << "\n";
    return 0;
}
