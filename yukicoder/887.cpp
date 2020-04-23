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
    int n;
    cin >> n;
    int ans1 = 0, ans2 = n;
    while(n != 1){
        if(n&1) n = 3*n+1;
        else n /= 2;
        ans1++;
        ans2 = max(ans2, n);
    }
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}