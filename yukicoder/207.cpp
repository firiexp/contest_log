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
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        int p = (i%3 == 0);
        for (auto &&j : to_string(i)) {
            if(j == '3') p = 1;
        }
        if(p) cout << i << "\n";
    }
    return 0;
}
