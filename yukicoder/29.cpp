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
    int n, ans = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < 3*n; ++i) {
        int k;
        cin >> k;
        if(m[k]%2){
            ans++;
        }
        m[k]++;
    }
    cout << ans + max(3*n-ans*2, 0)/4 << "\n";
    return 0;
}
