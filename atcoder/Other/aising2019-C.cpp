#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (int i = 0; i < h; ++i) {
        cin >> v[i];
    }
    ll ans = 0;
    for (int x = 0; x < 2; ++x) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if((i+j)%2 == x)
            }
        }
    }

    return 0;
}
