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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double k;
        cin >> k;
        string s;
        cin >> s;
        if(s == "BTC") k *= 380000;
        ans += k;
    }
    cout << setprecision(15) << ans << "\n";
    return 0;
}
