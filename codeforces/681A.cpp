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
    int n;
    cin >> n;
    int a = 0;
    for (int i = 0; i < n; ++i) {
        string s; int p, q;
        cin >> s >> p >> q;
        if(p >=  2400 && p < q) a = 1;
    }
    puts(a ? "YES" : "NO");
    return 0;
}
