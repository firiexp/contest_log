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
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int s = 0;
        sort(v.begin(), v.end());
        for (int i = 1; i < n-1; ++i) {
            s += v[i];
        }
        printf("%d\n", s/(n-2));
    }
    return 0;
}
