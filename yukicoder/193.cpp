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

int f(string &s){
    if(s.front() == '+' || s.front() == '-') return -MOD;
    if(s.back() == '+' || s.back() == '-') return -MOD;
    int ret = 0, c = 0, f = 1;
    for (auto &&i : s) {
        if(i == '+') ret += c*f, c = 0, f = 1;
        else if(i == '-') ret += c*f, c = 0, f = -1;
        else {
            c = c*10+(i-'0');
        }
    }
    ret += c*f;
    return ret;
}

int main() {
    string s;
    cin >> s;
    int ans = -MOD;
    s = s+s;
    for (int i = 0; i < s.size()/2; ++i) {
        string t = s.substr(i, s.size()/2);
        ans = max(ans, f(t));
    }
    cout << ans << "\n";
    return 0;
}
