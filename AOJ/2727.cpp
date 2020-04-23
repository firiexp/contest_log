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

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    string s, t;
    cin >> s >> t;
    string s1, s2;
    for (int i = 0; i < s.size(); ++i) {
        if(i&1) s1 += s[i];
        else s2 += s[i];
    }
    s1 += '?', s2 += '?';
    int cnt = 0;
    for (char i : t) {
        if(s1[cnt] == i) cnt++;
    }
    if(cnt+1 == s1.size()) {
        puts("Yes");
        return -0;
    }
    cnt = 0;
    for (char i : t) {
        if(s2[cnt] == i) cnt++;
    }
    if(cnt+1 == s2.size()) {
        puts("Yes");
        return -0;
    }
    puts("No");
    return 0;
}
