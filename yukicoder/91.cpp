#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int ok = 0, ng = MOD;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        int c = 0;
        c += (r <= mid ? r-mid : (r-mid)/2);
        c += (g <= mid ? g-mid : (g-mid)/2);
        c += (b <= mid ? b-mid : (b-mid)/2);
        (c >= 0 ? ok : ng) = mid;
    }
    cout << ok << "\n";
    return 0;
}
