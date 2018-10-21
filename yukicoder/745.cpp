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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(d == 10){
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    int ans = 0, p = a+b;
    for (int i = 1; i <= p; ++i) {
        int q;
        if(b) {
            q = 50, b--;

        }
        else {
            q = 100, a--;
        }
        for (int j = 0; j < (i-1)/100; ++j) {
            q *= 2;
        }
        ans += q;
    }
    cout << ans << "\n";
    return 0;
}
