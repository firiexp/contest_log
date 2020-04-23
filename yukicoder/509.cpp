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
    string s, t = "046889";
    cin >> s;
    int ans1 = static_cast<int>(s.size()*2 + 1), ans2 = static_cast<int>(s.size()+2);
    for (auto &&i : t) {
        for (auto &&j : s) {
            if(i == j) ans1++, ans2 += 2;
        }
    }
    cout << min(ans1, ans2) << "\n";
    return 0;
}
