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
    while(cin >> n, n) {
        int ans = 0;
        vector<string> v(n);
        string s;
        for (int i = 0; i < n; ++i) {
            string t;
            cin >> t;
            s += t;
            v[i] = t;
        }
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        vector<int> isreading(10, 0);
        vector<int> perm(10), val(10);
        for (int i = 0; i < n; ++i) {
            int vv = 1;
            for (int j = (int)v[i].size()-1; j >= 0; --j) {
                for (int k = 0; k < s.size(); ++k) {
                    if(v[i][j] == s[k]){
                        if(i == n-1) val[k] += vv;
                        else val[k] -= vv;
                        if(j == 0 && v[i].size() != 1) isreading[k] = 1;
                        break;
                    }
                }
                vv *= 10;
            }
        }
        iota(perm.begin(),perm.end(), 0);
        do {
            int sum = 0;
            for (int i = 0; i < 10; ++i) {
                if(perm[i] != 0) sum += perm[i]*val[i];
                else if(isreading[i]) sum = -INF<int>;
            }
            if(sum == 0) {
                ans++;
            }
        }while(next_permutation(perm.begin(),perm.end()));
        for (int i = 2; i <= 10-(int)s.size(); ++i) {
            ans /= i;
        }
        cout << ans << "\n";
    }
    return 0;
}