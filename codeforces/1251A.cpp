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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<pair<char, int>> v;
        v.emplace_back(s[0], 1);
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] == v.back().first) v.back().second++;
            else v.emplace_back(s[i], 1);
        }
        string ans;
        for (auto &&i : v) {
            if(i.second%2) ans += i.first;
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans << "\n";
    }
    return 0;
}