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
    v.emplace_back(-2);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int r = i;
        while(r < n){
            r++;
            if(v[r] < v[r-1]) break;
        }
        ans = max(ans, r-i);
        i = r-1;

    }
    cout << ans << "\n";
    return 0;
}