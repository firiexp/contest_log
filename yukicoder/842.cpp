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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                for (int l = 0; l <= d; ++l) {
                    for (int m = 0; m <= e; ++m) {
                        for (int n = 0; n <= f; ++n) {
                            if(i*500+j*100+k*50+l*10+m*5+n == g){
                                puts("YES");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}