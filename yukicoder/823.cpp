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
    int n, k;
    cin >> n >> k;
    if(n < k) {
        puts("INF");
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i <= 300000; ++i) {
        for (int j = 0; j <= k; ++j) {
            if((i&(i+j)) == n){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}