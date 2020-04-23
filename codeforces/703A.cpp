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
    int n;
    cin >> n;
    int a = 0;
    for (int i = 0; i < n; ++i) {
        int p, q;
        scanf("%d %d", &p, &q);
        if(p > q) a++;
        else if(p < q) a--;
    }
    if(a > 0){
        puts("Mishka");
    }else if(a < 0){
        puts("Chris");
    }else {
        puts("Friendship is magic!^^");
    }
    return 0;
}
