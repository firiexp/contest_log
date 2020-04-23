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
    int n;
    cin >> n;
    int a = 0, b = 0, c = 1, m = n;
    while(c < m){
        if(n%10 == 7) a += c*6, b += c*1;
        else a += c*(n%10);
        c *= 10; n /= 10;
    }
    printf("%d %d\n", a, b);
    return 0;
}
