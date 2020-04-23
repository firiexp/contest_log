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

bool solve(int n, int d){
    for (int i = 0; (i-1)*(i-1) <= d; ++i) {
        if(i+(d+i)/(i+1) <= n){
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, d;
        scanf("%d %d", &n, &d);
        puts(solve(n, d) ? "YES" : "NO");
    }
    return 0;
}