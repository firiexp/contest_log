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
    int k, n;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if(!s.count(v[i])) {
            s.insert(v[i]);
            ans.emplace_back(i+1);
            if(ans.size() == k) break;
        }
    }
    if(s.size() < k) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < ans.size(); ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}