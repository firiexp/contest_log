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
    vector<int> ans;
    for (int i = 2; i <= n; i += 2) {
        ans.emplace_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        ans.emplace_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}