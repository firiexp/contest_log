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
    int t;
    cin >> t;
    map<int, int> ans;
    for (int i = 3; i <= 1800; ++i) {
        if((i-2)*180%i == 0){
            ans[(i-2)*180/i]++;
        }
    }
    for (int i = 0; i < t; ++i) {
        int x; scanf("%d", &x);
        puts(ans[x] ? "YES" : "NO");
    }
    return 0;
}