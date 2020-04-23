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
    vector<int> a(n), b(n);
    for (auto &&i : a) scanf("%d", &i);
    for (auto &&j : b) scanf("%d", &j);
    vector<int> ans(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(b[i]);
    }
    for (int i = 0; i < n; ++i) {
        auto p = s.lower_bound(0);
        auto q = s.lower_bound(n-a[i]);
        if(q != s.end()){
            p = q;
        }
        ans[i] = (a[i]+*p) % n;
        s.erase(p);
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}