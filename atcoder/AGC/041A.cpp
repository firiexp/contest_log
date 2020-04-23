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
    ll n, a, b;
    cin >> n >> a >> b;
    if((b-a)%2 == 0) cout << (b-a)/2 << "\n";
    else {
        cout << min({
           a + (b-a)/2,
           n-b+1 + (b-a)/2
        });
    }
    return 0;
}