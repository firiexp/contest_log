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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; ++i) {
        if(n <= a)n += b;
        int c;
        cin >> c;
        n -= c;
        if(n < 0){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "complete\n";
    return 0;
}
