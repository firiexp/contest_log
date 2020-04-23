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
    int n;
    while(cin >> n, n){
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            if(max({a, b, c}) == 100) puts("A");
            else if(a+b >= 180) puts("A");
            else if(a+b+c >= 240) puts("A");
            else if(a+b+c >= 210) puts("B");
            else if(a+b+c >= 150 && max(a, b) >= 80) puts("B");
            else puts("C");
        }
    }
    return 0;
}