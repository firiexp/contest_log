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
    string A = "good", B = "problem";
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> dp1(n), dp2(n), dp3(n, 0);
        for (int i = 3; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                if(s[i-3+j] != A[j]) dp1[i]++;
            }
        }
        for (int i = n-7; i >= 0; --i) {
            for (int j = 0; j < 7; ++j) {
                if(s[i+j] != B[j]) dp2[i]++;
            }
        }
        for (int i = 6; i < n; ++i) {
            dp3[i] = dp3[i-1] + (dp2[i-6] == 0);
        }
        for (int i = n - 8; i >= 0; --i) {
            dp2[i] = min(dp2[i], dp2[i+1]);
        }
        int ans = INF<int>;
        for (int i = 3; i < n-7; ++i) {
            ans = min(ans, dp1[i]+dp2[i+1]+dp3[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}