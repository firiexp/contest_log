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
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p <= 10){
        vector<int> m(p), m2(p);
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            fill(m2.begin(),m2.end(), 0);
            m2[(s[i]-'0')%p]++;
            for (int j = 0; j < p; ++j) {
                m2[(j*10+(s[i]-'0'))%p] += m[j];
            }
            ans += m2[0];
            m = m2;
        }
        cout << ans << "\n";
    }else {
        map<int, int> m;
        int val = 0;
        vector<int> vs(n+1);
        ll aaa = 1;
        for (int i = n-1; i >= 0; --i) {
            val = (val + (s[i]-'0')*aaa)%p;
            aaa = (aaa*10)%p;
            m[val]++;
            vs[i] = val;
        }
        ll ans = 0;
        for (int i = n-1; i >= 0; --i) {
            ans += m[vs[i+1]];
            m[vs[i]]--;
        }
        cout << ans << "\n";
    }


    return 0;
}