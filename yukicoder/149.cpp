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
    int aw, ab, bw, bb, c, d;
    cin >> aw >> ab >> bw >> bb >> c >> d;
    for (int i = 0; i < c; ++i) {
        if(ab > 0) ab--, bb++;
        else aw--, bw++;
    }
    for (int j = 0; j < d; ++j) {
        if(bw > 0) bw--, aw++;
        else bb--, ab++;
    }
    cout << aw << "\n";
    return 0;
}
