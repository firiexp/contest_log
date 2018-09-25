#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    ll n, m;
    cin >> n >> m;
    if(n%m == 0){
        cout << 0 << "\n";
        return 0;
    }
    cout << m - __gcd(m, n) << "\n";

    return 0;
}
