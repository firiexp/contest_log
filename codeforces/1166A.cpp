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
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m[v[i].front()]++;
    }
    int ans = 0;
    for (auto &&j : m) {
        int x = (j.second+1)/2, y = j.second-x;
        ans +=  x*(x-1)/2+y*(y-1)/2;
    }
    cout << ans << "\n";
    return 0;
}