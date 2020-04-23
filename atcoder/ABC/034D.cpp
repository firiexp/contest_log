#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k;
    cin >> n >> k;
    using P = pair<long double, long double>;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        long double a, b;
        scanf("%Lf %Lf", &a, &b);
        v[i] = make_pair(b, a);
    }
    long double ok = 0, ng = 101;
    while(fabs(ok-ng) > 1e-12){
        auto x = (ok+ng)/2;
        sort(v.begin(), v.end(), [&](P a, P b){ return (a.first-x)*a.second > (b.first-x)*b.second; });
        long double w = 0, pw = 0;
        for (int i = 0; i < k; ++i) {
            pw += v[i].first*v[i].second; w += v[i].second;
        }
        if(pw >= w*x) ok = x;
        else ng = x;
    }
    cout << setprecision(10) << fixed << ok << "\n";
    return 0;
}
