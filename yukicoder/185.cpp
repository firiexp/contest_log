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
    int n, xx, yy;
    cin >> n >> xx >> yy;
    if(xx >= yy){
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        if(y-x != yy-xx){
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << yy-xx << "\n";
    return 0;
}
