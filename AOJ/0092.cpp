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
    while(cin >> n, n) {
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                v[i][j] = (s[j] == '.' ? min(i+1, j+1) : 0);
                if(!v[i][j]) continue;
                if(i) v[i][j] = min(v[i][j], v[i-1][j]+1);
                if(j) v[i][j] = min(v[i][j], v[i][j-1]+1);
                if(i && j) v[i][j] = min(v[i][j], v[i-1][j-1]+1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, v[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}