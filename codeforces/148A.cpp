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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int ans = 0;
    for (int i = 1; i <= e; ++i) {
        if(i%a == 0 || i%b == 0 || i%c == 0 || i%d == 0){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}