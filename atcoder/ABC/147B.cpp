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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


int main() {
    string s;
    cin >> s;
    int ans = 0;
    auto n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] != s[n-i-1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}