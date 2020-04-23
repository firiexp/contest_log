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

int main() {
    string s;
    cin >> s;
    int ans = 0;
    map<int, pair<int, int>> v;
    v[0] = make_pair(0, 0);
    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        c += (s[i] == 'A' ? 1 : -1);
        if(!v.count(c)){
            v[c] = make_pair(i+1, i+1);
        }else {
            v[c].second = i+1;
        }
    }
    for (auto &&i : v) {
        ans = max(ans, i.second.second-i.second.first);
    }
    cout << ans << "\n";
    return 0;
}
