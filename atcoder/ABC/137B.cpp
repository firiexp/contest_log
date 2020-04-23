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
    int k, x;
    cin >> k >> x;
    vector<int> ans;
    for (int i = -1000000; i <= 1000000; ++i) {
        if(abs(i-x) < k) ans.emplace_back(i);
    }
    for (int i = 0; i < ans.size(); ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}