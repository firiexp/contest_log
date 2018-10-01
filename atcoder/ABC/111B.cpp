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
    int n;
    cin >> n;
    for (int i = n; i <= 999; ++i) {
        auto k = to_string(i);
        if(k[0] == k[1] && k[1] == k[2]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
