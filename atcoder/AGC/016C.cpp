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
    int h, w, s, t;
    cin >> h >> w >> s >> t;
    if(h%s == 0 && w%t == 0) {
        puts("No");
        return 0;
    }
    puts("Yes");
    int a = 500000000/(s*t-1), b = a*(s*t-1)+1;
    b = -b;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(j) printf(" ");
            if(i%s == h%s && j%t == w%t) printf("%d", b);
            else printf("%d", a);
        }
        puts("");
    }
    return 0;
}
