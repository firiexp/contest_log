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
    vector<string> s(n);
    for (auto &&i : s) cin >> i;
    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].emplace_back(s[i][0], 1);
        for (int j = 1; j < s[i].size(); ++j) {
            if(v[i].back().first == s[i][j]){
                v[i].back().second++;
            }else {
                v[i].emplace_back(s[i][j], 1);
            }
        }
    }
    auto rec = [&](int x, char c, auto &&f) -> int {
        if(x == 0){
            int ans = 0;
            for (auto &&i : v[x]) {
                if(i.first == c) ans = max(ans, i.second);
            }
            return ans;
        }else if(v[x].size() == 1){
            return (v[x][0].first == c ? (f(x-1, c, f)+1)*(v[x][0].second+1)-1 : (f(x-1, c, f) != 0));
        }else if(v[x].front().first == v[x].back().first && v[x].front().first == c){
            int l = v[x].front().second, r = v[x].back().second;
            if(f(x-1, c, f)) return l+r+1;
            else return max(l, r);
        }else if(v[x].front().first == c){
            return v[x].front().second + (f(x-1, c, f) != 0);
        }else if(v[x].back().first == c){
            return v[x].back().second + (f(x-1, c, f) != 0);
        }
        int ans = f(x-1, c, f) != 0;
        for (auto &&i : v[x]) {
            if(i.first == c) ans = max(ans, i.second);
        }
        return ans;
    };
    int ans = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        ans = max(ans, rec(n-1, i, rec));
    }
    cout << ans << "\n";
    return 0;
}