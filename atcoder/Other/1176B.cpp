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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        vector<int> cnt(3);
        for (int i = 0; i < n; ++i) {
            cnt[v[i]%3]++;
        }
        int x = min(cnt[1], cnt[2]);
        cnt[1] -= x; cnt[2] -= x;
        cout << cnt[0]+x+cnt[1]/3+cnt[2]/3 << "\n";
    }
    return 0;
}