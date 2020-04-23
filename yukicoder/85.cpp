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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    if(n >= m) swap(n, m);
    if((n == 1 && m >= 3) || ((n*m)&1)){
        puts("NO");
    }else {
        puts("YES");
    }
    return 0;
}
