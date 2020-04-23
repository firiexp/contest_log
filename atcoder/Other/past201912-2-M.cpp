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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    double ok = 0, ng = 100001;
    using P = pair<int, int>;
    for (int i = 0; i < 50; ++i) {
        double mid = (ok+ng)/2;
        sort(a.begin(),a.end(), [&](P a, P b){
            return a.second - a.first*mid > b.second-b.first*mid;
        });
        double as = 0, bs = 0;
        for (int j = 0; j < 4; ++j) {
            as += a[j].first;
            bs += a[j].second;
        }
        double ans = (bs+a[4].second)/(as+a[4].first);
        for (int j = 0; j < m; ++j) {
            ans = max(ans, (bs+b[j].second)/(as+b[j].first));
        }
        if(ans >= mid) ok = mid;
        else ng = mid;
    }
    printf("%.10lf\n", ok);
    return 0;
}