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
    int k, n = 1;
    string s;
    cin >> k >> s;
    s += s;
    string t;
    for (int i = 0; i < k-1; ++i) {
        n *= 4;
    }
    while(n){
        for (int i = 0; i < n; ++i) t += 'J';
        for (int i = 0; i < n; ++i) t += 'O';
        for (int i = 0; i < n; ++i) t += 'I';
        n /= 4;
    }
    vector<int> c;
    for (int i = 0; i+1 < t.size(); ++i) {
        if(t[i] != t[i+1]) c.emplace_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < t.size(); ++i) {
        if(s[i] != t[i]) cnt++;
    }
    int ans = cnt;
    for (int i = 0; i+t.size() < s.size(); ++i) {
        cnt += (s[i+t.size()] != t.back()) - (s[i] != t.front());
        for (auto &&j : c) {
            cnt += (s[i+j+1] != t[j]) -(s[i+j+1] != t[j+1]);
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}