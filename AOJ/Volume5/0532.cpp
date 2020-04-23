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
    for (int i = 0; i < 3; ++i) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        int t = (h2-h1)*3600+(m2-m1)*60+s2-s1;
        printf("%d %d %d\n", t/3600, t/60%60, t%60);
    }
    return 0;
}
