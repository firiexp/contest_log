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
    int n;
    cin >> n;
    if(n%3) {
        puts("NO");
        return 0;
    }
    puts("YES");
    vector<int> v(2*n);
    v[0] = 1;
    v[1] = 2*n-2;
    v[2] = n+2;
    int k = v[0]+v[1]+v[2];
    for (int i = 3; i < 2*n; ++i) {
        v[i] = k-(v[i-1]+v[i-2])+i%2;
    }
    for (int i = 0; i < 2*n; ++i) {
        if(i) cout << " ";
        cout << v[i];
    }
    puts("");
    return 0;
}