#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) {
        scanf("%d", &i);
        if(i == 0){
            cout << n << "\n";
            return 0;
        }
    }
    int a = 0, b = 0;
    ll x = v[0];
    int ans = (x <= k ? 1 : 0);
    while(b != n-1){
        if(x*v[b+1] <= k){
            b++;
            x *= v[b];
        }else {
            if(a == b){
                a++; b++;
                x = v[a];
            }else {
                x /= v[a];
                a++;
            }
        }
        ans = max(ans, (x <= k ? b-a+1 : 0));
    }
    cout << ans << "\n";
    return 0;
}
