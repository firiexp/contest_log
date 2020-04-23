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
    int b;
    cin >> b;
    int ans = 0;
    for (int i = 2; i < b; ++i) {
        int j = i;
        while(j < b) j = j*3/2;
        if(j == b) ans++;
    }
    cout << ans << "\n";
    return 0;
}
