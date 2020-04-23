#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>


static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    long double b, ans1 = 0, ans2 = 0;
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        long double a;
        cin >> a;
        ans1 += a*pow(b, a-1);
        if(fabs(a+1) < 1e-5) ans2 += log(b);
        else ans2 += pow(b, a+1)/(a+1);
    }
    cout << setprecision(15) << ans1 << "\n";
    cout << ans2 << "\n";
    return 0;
}
