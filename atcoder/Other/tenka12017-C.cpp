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
    ll N;
    cin >> N;
    for (ll n = 1; n <= 3500; ++n) {
        for (ll w = 1; w <= 3500; ++w) {
            if(4*n*w-N*w-N*n < 1) continue;
            if((N*n*w)%(4*n*w-N*w-N*n)) continue;
            cout << (N*n*w)/(4*n*w-N*w-N*n) << " " <<  n << " " << w << "\n";
            return 0;
        }
    }
    return 0;
}
