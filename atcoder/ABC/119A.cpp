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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    if(a > 2019) puts("TBD");
    else if(a == 2019){
        if(b >= 5) puts("TBD");
        else puts("Heisei");
    }else puts("Heisei");
    return 0;
}
