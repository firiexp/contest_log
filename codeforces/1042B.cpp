#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    vector<ll> x(7, 100000000000LL);
    vector<string> ss{"A", "B", "C", "AB", "BC", "AC", "ABC"};
    for (int i = 0; i < n; ++i) {
        ll p;
        string s;
        cin >> p >> s;
        sort(s.begin(), s.end());
        for (int j = 0; j < 7; ++j) {
            if(s == ss[j]){
                x[j] = min(x[j], p);
            }
        }
    }
    ll ans = min({
        x[0]+x[1]+x[2], x[3]+x[2], x[0]+x[4], x[3] + x[4], x[6], 100000000000LL,
        x[1]+x[5],x[3]+x[5],x[4]+x[5]
    });
    cout << (ans < 100000000000LL ? ans : -1) << "\n";
    return 0;
}
