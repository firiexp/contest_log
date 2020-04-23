#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, q;
    while(cin >> n >> q, n|q){
        array<int, 101> v{};
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                v[x]++;
            }
        }
        int ans = 0, m = q-1;
        for (int i = 0; i <= 100; ++i) {
            if(m < v[i]){
                ans = i;
                m = v[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
