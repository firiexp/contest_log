#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    string s = "RGYB";
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x = i+j+1000, y = i-j+1000;
            cout << s[(x%(2*d) >= d)+(y%(2*d) >= d)*2];
        }
        puts("");
    }
    return 0;
}