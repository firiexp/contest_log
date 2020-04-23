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
    int n, l, r;
    while(cin >> n >> l >> r, n){
        vector<int> v(n+1, 1);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            for (int j = 0; j <= n; ++j) {
                if(i%v[j] == 0) {
                    cnt += (j^1)&1;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}