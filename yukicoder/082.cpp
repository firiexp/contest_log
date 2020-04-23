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
    int h, w, a;
    char c;
    cin >> h >> w >> c;
    a = (c == 'W');
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if(a) cout << "W";
            else cout << "B";
            a ^= 1;
        }
        if(h%2 == 0) a ^= 1;
        cout << "\n";
    }
    return 0;
}
