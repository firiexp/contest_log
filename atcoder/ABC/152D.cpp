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
    int n;
    cin >> n;
    map<pair<int, int>, int> v;
    for (int i = 1; i <= n; ++i) {
        string s = to_string(i);
        v[make_pair<int>(s.front(), s.back())]++;
    }
    ll ans = 0;
    for (auto &&i : v) {
        int l, r;
        tie(l, r) = i.first;
        if(v.count(make_pair(r, l))){
            ans += i.second*v[make_pair(r, l)];
        }
    }
    cout << ans << "\n";
    return 0;
}