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
    int n;
    cin >> n;
    vector<string> v(n);
    int ans = 0, a = 0, b = 0, ab = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j+1 < v[i].size(); ++j) {
            if(v[i][j] == 'A' && v[i][j+1] == 'B') ans++;
        }
        if(v[i].front() == 'B' && v[i].back() == 'A') ab++;
        if(v[i].front() == 'B') b++;
        if(v[i].back() == 'A')a++;
    }
    ans += min(a, b);
    if(a == b && b == ab && a > 0) --ans;
    cout << ans << "\n";
    return 0;
}