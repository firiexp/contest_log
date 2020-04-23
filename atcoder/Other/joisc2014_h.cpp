#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }
int main() {
    map<pair<int, int>, int> m;
    int n; string s;
    cin >> n >> s;
    array<int, 3> v{};
    int ans = 0;
    m[make_pair(0, 0)] = -1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'J') v[0]++;
        else if(s[i] == 'O') v[1]++;
        else v[2]++;
        pair<int, int> p = {v[1]-v[0], v[2]-v[1]};
        if(m.count(p)) chmax(ans, i-m[p]);
        else m[p] = i;
    }
    cout << ans << "\n";
    return 0;
}
