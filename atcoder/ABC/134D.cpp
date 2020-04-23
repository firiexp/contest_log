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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> ans;
    vector<int> balls(n+1);
    for (int j = n; j >= 1; --j) {
        int cnt = v[j-1];
        for (int k = 2*j; k <= n; k += j) {
            cnt ^= balls[k];
        }
        balls[j] = cnt;
        if(cnt) ans.emplace_back(j);
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}