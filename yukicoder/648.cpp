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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    uint64_t x;
    cin >> x;
    x = 8*x+1;
    ll y = sqrt(x)-10;
    for (uint64_t i = max((ll)0,y); i < y+30; ++i) {
        if(i*i == x){
            puts("YES");
            cout << (i-1)/2 << "\n";
            return 0;
        }
    }
    puts("NO");
    return 0;
}
