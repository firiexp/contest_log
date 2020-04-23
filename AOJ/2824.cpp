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
    int t, d, l;
    while(cin >> t >> d >> l, t){
        vector<int> v(t);
        int ans = 0, p = -1;
        for (auto &&i : v) scanf("%d", &i);
        for (int i = 0; i < t; ++i) {
            if(i && v[i-1] >= l) p = d;
            else p--;
            if(p > 0) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}