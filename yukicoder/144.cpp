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
    int n; double p;
    cin >> n >> p;
    vector<double> dp(n+1, 1);
    vector<int> divisors(n+1, 0);
    vector<double> pp(n+1, 1-p);
    pp[0] = 1;
    for (int i = 2; i <= n; ++i) {
        pp[i] *= pp[i-1];
    }
    double ans = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2*i; j <= n; j += i) {
            divisors[j]++;
        }
        ans += pp[divisors[i]];
    }
    cout << setprecision(10) << ans << "\n";
    return 0;
}
