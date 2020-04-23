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
    while (cin >> n >> m, n > 0 && m > 0){
        vector<int> v(n), u(m);
        for (auto &&i : v) scanf("%d", &i);
        for (auto &&j : u) scanf("%d", &j);
        int p = 0;
        for (int i = 0; i < m; ++i) {
            p += u[i];
            p += v[p];
            if(p >= n-1) {
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}
