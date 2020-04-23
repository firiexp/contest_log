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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            string s = to_string(v[i]*v[j]);
            bool valid = true;
            for (int k = 0; k+1 < s.size(); ++k) {
                if(s[k+1]-s[k] != 1) valid = false;
            }
            if(valid){
                ans = max(ans, stoi(s));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}