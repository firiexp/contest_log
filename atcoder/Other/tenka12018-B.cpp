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
    int a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < k; ++i) {
        if(i%2 == 0){
            b += a/2;
            a /= 2;
        }else {
            a += b/2;
            b /= 2;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}
