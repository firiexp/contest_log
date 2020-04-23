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
        vector<string> v(n);
        for(auto &&i : v) cin >> i;
        vector<int> cnt(2);
        int odd = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &&j : v[i]) {
                cnt[j-'0']++;
            }
            if((v[i].size()&1)) odd++;
        }
        cout << n - min(1, max(0, cnt[0]%2+cnt[1]%2-odd)) << "\n";
    }
    return 0;
}