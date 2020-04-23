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
const int B = 700;
int v[B+1][B+1];
int u[500001];
int main() {
    int q;
    cin >> q;
    for (int i = 0; i <= B; ++i) {
        for (int j = 0; j <= B; ++j) {
            v[i][j] = 0;
        }
    }
    for (int i = 0; i <= 500000; ++i) {
        u[i] = 0;
    }
    while(q--){
        int t, x, y; scanf("%d %d %d", &t, &x, &y);
        if(t == 1){
            for (int i = 1; i <= B; ++i) {
                v[i][x%i] += y;
            }
            u[x] += y;
        }else {
            if(x <= B){
                printf("%d\n", v[x][y]);
            }else {
                int ans = 0;
                for (int i = y; i <= 500000; i += x) {
                    ans += u[i];
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}