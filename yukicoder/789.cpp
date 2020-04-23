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


template<class T>
class BIT {
    vector<T> bit;
public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> v(n);
    vector<int> z;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &v[i][j]);
        }
        if(v[i][0] == 0){
            z.emplace_back(v[i][1]);
        }
    }
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    BIT<int> S(z.size()+1);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i][0] == 0){
            S.add(lower_bound(z.begin(),z.end(), v[i][1]) - z.begin() + 1, v[i][2]);
        }else {
            int l = lower_bound(z.begin(),z.end(), v[i][1]) - z.begin();
            int r = upper_bound(z.begin(),z.end(), v[i][2]) - z.begin();
            ans += S.sum(r) - S.sum(l);
        }
    }
    cout << ans << "\n";
    return 0;
}