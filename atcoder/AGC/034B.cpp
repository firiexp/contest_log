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
    if(s.size() <= 2){
        puts("0");
        return 0;
    }
    int n = s.size();
    s += "X";
    string t;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'B' && s[i+1] == 'C') t += "X", i++;
        else t += s[i];
    }
    ll ans = 0, x = 0;
    for (auto &&j : t) {
        if(j == 'A') x++;
        else if(j == 'X') ans += x;
        else x = 0;
    }
    cout << ans << "\n";
    return 0;
}