#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int m, n;
    cin >> m >> n;
    int ans = 0;
    while(m != n && (m|n) != 0){
        if(m < n){
            ans++;
            swap(m, n);
        }else {
            if(__gcd(m, n) == n){
                ans += (m-1)/n;
                m = n;
            }else {
                ans += m/n;
                m -= m/n*n;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
