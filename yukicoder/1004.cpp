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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    u32 a, b, x0, n;
    cin >> a >> b >> x0 >> n;
    if(n == 0){
        puts("0 0");
        return 0;
    }
    if(x0&1) cout << n/2 << " 0\n";
    else cout << 0 << " " << n/2 << "\n";
    return 0;
}