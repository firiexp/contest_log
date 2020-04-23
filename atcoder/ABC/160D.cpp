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
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> ans(n+1);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int val = min({j-i, abs(x-i)+abs(y-j)+1, abs(x-j)+abs(y-i)+1});
            ans[val]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}