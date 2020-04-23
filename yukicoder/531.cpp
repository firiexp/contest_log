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
    int n, m;
    cin >> n >> m;
    if(n <= m) cout << 1 << "\n";
    else if(n%2 == 0 && n <= 2*m) cout << 2 << "\n";
    else cout << -1 << "\n";
    return 0;
}
