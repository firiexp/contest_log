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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n+1);
    for (int i = n - 1; i >= 0; --i) {
        v[i] = v[i+1] + (s[i] == '+') - (s[i] == '-');
    }
    ll ans = 0;
    vector<int> u;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'M') u.emplace_back(v[i]);
    }
    sort(u.begin(),u.end());
    for (int i = 0; i < u.size()/2; ++i) {
        ans += u[(int)u.size()-i-1]-u[i];
    }
    cout << ans << "\n";
    return 0;
}