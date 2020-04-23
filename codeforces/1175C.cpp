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
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int ans = INF<int>, d = 0;
        for (int i = 0; i+k < n; ++i) {
            if(ans > (v[i+k]-v[i]+1)/2){
                ans = (v[i+k]-v[i]+1)/2;
                d = v[i]+ans;
            }
        }
        cout << d << "\n";
    }
    return 0;
}