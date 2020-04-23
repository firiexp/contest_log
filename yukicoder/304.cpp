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
    for (int i = 0; i <= 999; ++i) {
        printf("%03d\n", i);
        fflush(stdin);
        string s;
        cin >> s;
        if(s == "unlocked") return 0;
    }
    return 0;
}
