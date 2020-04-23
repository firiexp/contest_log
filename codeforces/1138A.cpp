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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> a(n, 0), b(n, 0);
    (v[n-1] == 1 ? a : b)[n-1]++;
    for (int i = n-2; i >= 0; --i) {
        if(v[i] == 1){
            a[i] = a[i+1]+1;
        }else {
            b[i] = b[i+1]+1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i]){
            if(i+a[i] < n && b[i+a[i]] >= a[i]) ans = max(ans, 2*a[i]);
        }else if(b[i]){
            if(i+b[i] < n && a[i+b[i]] >= b[i]) ans = max(ans, 2*b[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
