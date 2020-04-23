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
    int t , b;
    cin >> t >> b;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        string ans;
        if(n == 0) puts("0");
        else {
            while(n){
                int r = n%(-b);
                if(r < 0) r -= b;
                n = (n-r)/b;
                ans += (char)('0'+r);
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
        }
    }
    return 0;
}
