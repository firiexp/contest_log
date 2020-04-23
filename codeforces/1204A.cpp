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
    int f = 0;
    for (int i = 1; i < s.size(); ++i) {
        if(s[i] != '0') f = 1;
    }
    int ans = s.size()/2;
    if(f && s.size()%2) ans++;
    cout << ans << "\n";
    return 0;
}