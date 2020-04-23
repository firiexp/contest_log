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
    int n, m, k;
    cin >> n >> m >> k;
    bitset<501> b;
    b.set(k);
    for (int i = 0; i < n; ++i) {
        bitset<501> c;
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            c |= (b >> x);
        }
        b = c;
    }
    if(!b.count()){
        puts("-1");
    }else {
        for (int i = 0; i <= k; ++i) {
            if(b[i]) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}