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
    int m, n, N;
    cin >> m >> n >> N;
    int ans = 0, amari = 0;
    while(N > 0){
        ans += N;
        amari += N;
        N = amari/m*n;
        amari -= N*m/n;
    }
    cout << ans << "\n";
    return 0;
}
