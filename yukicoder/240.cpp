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
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2, 0},
        dy[] = {-1, 1, -2, 2, -2, 2, -1, 1, 0};
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                if(dx[i]+dx[j]+dx[k] == x && dy[i] + dy[j] + dy[k] == y){
                    puts("YES");
                    return -0;
                }
            }
        }
    }
    puts("NO");
    return -0;
}
