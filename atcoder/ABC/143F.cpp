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
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[v[i]-1]++;
    }
    sort(cnt.begin(),cnt.end());
    while(cnt.back() == 0) cnt.pop_back();
    vector<int> ans(n);
    int p = 0;
    int s = n;
    for (int k = 1; k <= n; ++k) {
        int x = k-p;
        while(!cnt.empty() && cnt.back() > s/x){
            s -= cnt.back();
            cnt.pop_back();
            p++;
            x--;
        }
        ans[k-1] = s / x;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}