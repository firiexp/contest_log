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
    map<int, int> map1;
    int p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        map1[a]++;
        p++;
    }
    for (int j = 0; j < m; ++j) {
        int b;
        scanf("%d", &b);
        if(map1[b]) q++;
        else p++;
    }
    cout << setprecision(10) << 1.0*q/p << "\n";
    return 0;
}
