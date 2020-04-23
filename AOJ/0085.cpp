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
    int n, m;
    while(cin >> n >> m, n){
        auto f = [&](int n, int m, auto &&f) -> int{
            if(n == 1) return 0;
            return (f(n-1, m, f)+m)%n;
        };
        printf("%d\n", f(n, m, f)+1);
    }
    return 0;
}