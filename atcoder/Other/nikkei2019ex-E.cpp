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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        for (int j = 2; j < 7; ++j) {
            if(i%j == 0) s += ('a'-2+j);
        }
        if(s.empty()) printf("%d\n", i);
        else cout << s << "\n";
    }
    return 0;
}
