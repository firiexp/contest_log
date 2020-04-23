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
    int n, d;
    cin >> n >> d;
    int ans = 0, k = 0;
    for (int i = 0; i < d; ++i) {
        string s;
        cin >> s;
        int x = 0;
        for (auto &&j : s) x|= (j == '0');
        if(x) k++;
        else k = 0;
        ans = max(ans, k);
    }
    cout << ans << "\n";
    return 0;
}