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
    int a, b, c;
    cin >> a >> b >> c;
    int t = 0;
    for (int i = 0; i <= 3600; ++i) {
        int p = t, q = (t+a);
        for (int j = 0; j <= 3600; ++j) {
            if(p <= 60*j+c && 60*j+c <= q){
                cout << 60*j+c << "\n";
                return 0;
            }
        }
        t += a+b;
    }
    puts("-1");
    return 0;
}