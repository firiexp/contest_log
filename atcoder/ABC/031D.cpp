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

template <class T>
T pow_ (T x, T n, T M){
    uint64_t u = 1, xx = x;
    while (n > 0){
        if (n&1) u = u * xx % M;
        xx = xx * xx % M;
        n >>= 1;
    }
    return static_cast<T>(u);
};

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> v(k, 1);
    vector<string> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < pow_(3, k, MOD); ++i) {
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            int s = 0;
            for (auto &&l : a[j]) {
                s += v[l-'1'];
            }
            if(s != b[j].size()) ok = 0;
        }
        if(ok){
            vector<string> ans(k);
            for (int j = 0; j < n; ++j) {
                int s = 0;
                for (auto &&l : a[j]) {
                    string t = b[j].substr(s, v[l-'1']);
                    if(!ans[l-'1'].empty() && ans[l-'1'] != t){
                        ok = 0;
                    }
                    ans[l-'1'] = t;
                    s += v[l-'1'];
                }
                if(s != b[j].size()) ok = 0;
            }
            if(ok){
                for (int j = 0; j < k; ++j) {
                    cout << ans[j] << "\n";
                }
                return 0;
            }
        }
        v.back()++;
        for (int j = k-1; j >= 1; --j) {
            if(v[j] > 3) v[j] = 1, v[j-1]++;
            else break;
        }
    }
    return 0;
}