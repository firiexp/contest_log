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
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if(v[i] & 1) ans[i] = min(v[i]/2, v[i]/2+1*(v[i]/abs(v[i])));
        else ans[i] = v[i]/2;
    }
    ll s = accumulate(ans.begin(),ans.end(), 0LL);
    for (int i = 0; i < n; ++i) {
        if(s < 0 && v[i]%2){
            s++;
            ans[i]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}