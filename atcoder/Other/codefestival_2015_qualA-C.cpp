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
    int n, t;
    cin >> n >> t;
    vector<int> v;
    ll s = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        s += a;
        v.emplace_back(b-a);
        y += v[i];
    }
    if(s+y > t){
        puts("-1");
        return 0;
    }
    sort(v.begin(), v.end());
    int ok = n, ng = -1;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        ll x = s;
        for (int i = 1; i <= mid; ++i) {
            x += v[i-1];
        }
        if(x <= t){
            ok = mid;
        }else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
