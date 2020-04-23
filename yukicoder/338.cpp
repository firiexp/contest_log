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
    int a, b;
    cin >> a >> b;
    int ans = INF<int>;
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 200; ++j) {
            if(i+j == 0) continue;
            if(a == (100*i +(i+j)/2)/(i+j) && b == (100*j+(i+j)/2)/(i+j)) ans = min(ans, i+j);
        }
    }
    cout << ans << "\n";
    return 0;
}
