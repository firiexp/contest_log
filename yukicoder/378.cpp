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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    ll n, a = 0;
    cin >> n;
    ll b = n;
    while(n){
        a += n;
        n /= 2;
    }
    cout << b*2-a << "\n";
    return 0;
}
