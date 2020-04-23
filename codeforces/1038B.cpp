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

template<class T>
vector<T> divisor(T n){
    vector<T> ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return(ret);
}

int main() {
    int n;
    cin >> n;
    if(n <= 2){
        puts("No");
        return 0;
    }
    puts("Yes");
    int x = (n%2 ? n : n/2);
    printf("1 %d\n", x);
    printf("%d", n-1);
    for (int i = 1; i <= n; ++i) {
        if(i != x){
            printf(" %d", i);
        }
    }
    puts("");
    return 0;
}