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
    vector<pair<char, ll>> v;
    v.emplace_back(s[0], 1);
    for (int i = 1; i < s.size(); ++i) {
        if(v.back().first == s[i]){
            v.back().second++;
        }else v.emplace_back(s[i], 1);
    }
    ll ans = 0;
    int l = 0, r = v.size();
    if(v.front().first == '>'){
        ans += (v.front().second+1)*(v.front().second)/2;
        l++;
    }
    if(v.back().first == '<'){
        ans += (v.back().second+1)*(v.back().second)/2;
        r--;
    }
    for (int i = l; i < r; i += 2) {
        ans += max(v[i].second, v[i+1].second);
        ans += (v[i].second-1)*(v[i].second)/2;
        ans += (v[i+1].second-1)*(v[i+1].second)/2;
    }
    cout << ans << "\n";
    return 0;
}