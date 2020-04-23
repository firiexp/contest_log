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
    int a, b;
    cin >> a >> b;
    vector<int> cnt(30);
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < 30; ++i) {
        if(s[i] == 'W') cnt[i] = 30;
        else cnt[i] = cur++;
    }
    vector<vector<int>> v(21);
    for (int i = 0; i < (1 << 20); ++i) {
        v[__builtin_popcount(i)].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i <= 20; ++i) {
        for (auto &&j : v[i]) {
            string t;
            int ok = 1;
            for (int k = 0; k < 30; ++k) {
                if(!(j & (1 << cnt[k]))){
                    t += s[k];
                    if(t.back() == 'R' && t.size() > a && t[t.size()-a-1] == 'R') ok = 0;
                    if(t.back() == 'B' && t.size() > b && t[t.size()-b-1] == 'B') ok = 0;
                }
            }
            if(ok){
                cout << 30-i << "\n";
                return 0;
            }
        }
    }
    return 0;
}