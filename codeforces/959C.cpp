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
    int n;
    cin >> n;
    if(n <= 5){
        puts("-1");
    }else {
        puts("1 2");
        for (int i = 3; i <= n; ++i) {
            if(i&1) printf("%d %d\n", 1, i);
            else printf("%d %d\n", 2, i);
        }
    }
    for (int i = 2; i <= n; ++i) {
        printf("%d %d\n", 1, i);
    }
    return 0;
}