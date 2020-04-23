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
    int a, b;
    scanf("%d:%d", &a, &b);
    int p = a*60+b;
    p += 5;
    if(p >= 1440) p -= 1440;
    printf("%02d:%02d", p/60, p%60);
    return 0;
}
