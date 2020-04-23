#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        vector<array<int, 4>> v(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &v[i][j]);
            }
        }
        int p, q, r, c;
        cin >> p >> q >> r >> c;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i][1] <= p && v[i][2] <= q && v[i][3] <= r && v[i][1]*4+v[i][2]*9+v[i][3]*4 <= c){
                cnt++;
                cout << v[i][0] << "\n";
            }
        }
        if(!cnt) puts("NA");
    }
    return 0;
}