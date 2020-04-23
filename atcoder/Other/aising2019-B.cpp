#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int p=0, q=0, r=0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if(k <= a) p++;
        else if(k <= b) q++;
        else r++;
    }
    cout << min({p, q, r}) << "\n";
    return 0;
}
