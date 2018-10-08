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
    ll a, k;
    cin >> a >> k;
    if(k == 0) {
        cout << 2000000000000LL-a << "\n";
    }else {
        int p = 0;
        while(a < 2000000000000LL){
            a = a*(k+1)+1;
            p++;
        }
        cout << p << "\n";
    }
    return 0;
}
