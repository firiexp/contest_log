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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (auto &&i : a) scanf("%lld", &i);
    for (auto &&j : b) scanf("%lld", &j);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ng = -1, ok = INF<int>;
    while(ok - ng > 1){
        ll mid = (ok+ng)/2;
        int c1 = 0, c2 = 0, matched = 0;
        while(c1 != n && c2 != m){
            if(b[c2] < a[c1]-mid){
                c2++;
            }else if(b[c2] <= a[c1]+mid){
                c1++, c2++;
                matched++;
            }else {
                c1++;
            }
        }
        if(matched < k) ng = mid;
        else ok = mid;
    }
    cout << ok << "\n";
    return 0;
}
