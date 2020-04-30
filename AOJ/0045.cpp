#include <iostream>
#include <algorithm>
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
    int a, b;
    int asum = 0, bsum = 0, cnt = 0;
    while(scanf("%d,%d", &a, &b) != EOF){
        asum += a*b; bsum += b; cnt++;
    }
    printf("%d\n%d\n", asum, (bsum*2+cnt)/(2*cnt));
    return 0;
}