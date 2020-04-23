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
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= 100000; ++i) {
        if(n-p*i > 0 && __builtin_popcount(n-p*i) <= i && n-p*i >= i){
            cout << i << "\n";
            return 0;
        }
    }
    puts("-1");
    return 0;
}