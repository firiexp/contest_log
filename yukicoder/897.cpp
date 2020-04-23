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
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n, k;
        cin >> n >> k;
        ll a = 0, b = 1, ans = 0;
        if(k == 1) {
            cout << n-1 << "\n";
        }else{
                while(a < n){
                    a += b;
                    b *= k;
                    ans++;
                }
                cout << ans-1 << "\n";
        }
    }
    return 0;
}