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
    int g = 0, c = 0, p = 0, gg, cc, pp;
    cin >> gg >> cc >> pp;
    string s;
    cin >> s;
    for (auto &&i : s) {
        if(i == 'G') g++;
        else if(i == 'C') c++;
        else p++;
    }
    int dg = min(gg, c), dc = min(cc, p), dp = min(pp, g);
    gg -= dg, c -= dg, cc -= dc, p -= dc, pp -= dp, g -= dp;
    int ans = (dg+dc+dp)*3 + min(g, gg)+min(c, cc)+min(p, pp);
    cout << ans << "\n";
    return 0;
}
