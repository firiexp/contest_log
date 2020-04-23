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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, ~n){
        string ans;
        while(n){
            ans += to_string(n&3);
            n >>= 2;
        }
        if(ans.empty()) ans = "0";
        reverse(ans.begin(),ans.end());
        cout << ans << "\n";
    }
    return 0;
}