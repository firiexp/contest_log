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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size();
    if(n == 1) {
        puts("0");
        return 0;
    }
    int d = v[0] < v[1];
    int ans = 2;
    for (int i = 1; i+1 < n ; ++i) {
        if(d != (v[i] < v[i+1])){
            d ^= 1;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}