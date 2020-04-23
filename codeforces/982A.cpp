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
    string s;
    cin >> s;
    int ok = 1;
    s = '0' + s + '0';
    n += 2;
    for (int i = 0; i+1 < n; ++i) {
        if(s[i] == '1' && s[i+1] == '1') ok = 0;
    }
    for (int i = 1; i+1 < n; ++i) {
        if(s[i] == '0' && s[i+1] == '0' && s[i-1] == '0') ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}