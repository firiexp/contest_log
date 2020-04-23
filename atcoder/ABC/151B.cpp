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
    int n, k, m;
    cin >> n >> k >> m;
    int x = 0;
    for (int i = 0; i < n-1; ++i) {
        int xx;
        cin >> xx;
        x += xx;
    }
    if(m*n-x > k){
        puts("-1");
    }
    else cout << max(0, m*n-x) << "\n";
    return 0;
}