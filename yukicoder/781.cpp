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
    int x, y;
    cin >> x >> y;
    vector<int> v(y+1);
    for (int i = 1; i <= 4000; ++i) {
        int w = i*i;
        if(w > y) continue;
        for (int j = 0; j <= 4000; ++j) {
            if(w+j*j > y) continue;
            v[w+j*j]++;
        }
    }
    int ans = 0;
    for (int i = x; i <= y; ++i) {
        ans = max(ans, v[i]);
    }
    cout << 4*ans << "\n";
    return 0;
}
