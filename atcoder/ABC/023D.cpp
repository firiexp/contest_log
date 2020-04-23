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
    vector<ll> h(n), s(n);
    for (int i = 0; i < n; ++i) {
        scanf("%li %li", &h[i], &s[i]);
    }
    ll ok = INF<ll>/1000, ng = 0;
    while(ok-ng > 1){
        ll x = (ok+ng)/2;
        vector<ll> t(n);
        int valid = true;
        for (int i = 0; i < n; ++i) {
            if(x < h[i]) valid = false;
            t[i] = (x-h[i])/s[i];
        }

        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i) {
            if(i > t[i]) valid = false;
        }
        (valid ? ok : ng) = x;
    }
    cout << ok << "\n";
    return 0;
}
