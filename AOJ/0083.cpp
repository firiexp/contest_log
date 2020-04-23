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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    using P = array<int, 3>;
    P v{};
    while(scanf("%d %d %d", &v[0], &v[1], &v[2]) != EOF){
        if(v <= P{1868, 9, 7}) {
            puts("pre-meiji");
            continue;
        }
        if(v <= P{1912, 7, 29}) printf("meiji"), v[0] -= 1867;
        else if(v <= P{1926, 12, 24}) printf("taisho"), v[0] -= 1911;
        else if(v <= P{1989, 1, 7}) printf("showa"), v[0] -= 1925;
        else printf("heisei"), v[0] -= 1988;
        printf(" %d %d %d\n", v[0], v[1], v[2]);
    }
    return 0;
}