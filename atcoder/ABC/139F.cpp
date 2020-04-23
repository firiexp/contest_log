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
    long double ans = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if(a|b){
            v.emplace_back(a, b);
        }
    }
    n = v.size();
    sort(v.begin(),v.end(), [](auto a, auto b){
        return atan2(a.first, a.second) < atan2(b.first, b.second);
    });
    for (int i = 0; i < n; ++i) {
        v.emplace_back(v[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int l = i, r = j + (i > j ? n : 0);
            int y = 0, x = 0;
            for (int k = l; k <= r; ++k) {
                y += v[k].first; x += v[k].second;
            }
            ans = max(ans, hypot<long double>(y, x));
        }
    }
    printf("%.15Lf\n", ans);
    return 0;
}