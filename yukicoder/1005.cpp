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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<pair<int, int>> v;
    for (int i = 0; i+m <= n; ++i) {
        int ok = 1;
        for (int j = 0; j < m; ++j) {
            if(s[i+j] != t[j]) ok = 0;
        }
        if(ok) v.emplace_back(i, i+m-1);
    }
    if(t.size() == 1 && !v.empty()){
        puts("-1");
        return 0;
    }
    int ans = 0, val = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(val <= v[i].first){
            ans++;
            val = v[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}