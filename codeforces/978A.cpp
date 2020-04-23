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
    for (auto &&j : v) scanf("%d", &j);
    vector<int> ans; set<int> s;
    for (int i = n - 1; i >= 0; --i) {
        if(!s.count(v[i])) {
            s.insert(v[i]);
            ans.emplace_back(v[i]);
        }
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