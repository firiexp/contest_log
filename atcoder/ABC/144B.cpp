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
    int n;
    cin >> n;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if((i+1)*(j+1) == n) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}