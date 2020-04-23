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
    ll a, b;
    cin >> a >> b;
    cout << "YES\n";
    for (int i = 0; i < (b-a+1)/2; ++i) {
        printf("%lld %lld\n", a+2*i, a+2*i+1);
    }
    return 0;
}
