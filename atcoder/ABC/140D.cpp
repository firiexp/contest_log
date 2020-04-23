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
    int n, k; string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        if(s[i] != s[i+1]) cnt++;
    }
    for (int i = 0; i < k; ++i) {
        cnt = max(0, cnt-2);
    }
    cout << n-cnt-1 << "\n";
    return 0;
}