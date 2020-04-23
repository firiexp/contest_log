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
    int m;
public:
    BIT(int n): bit(vector<T>(n+1, 0)){
        m = 1;
        while(m < n) m <<= 1;
    }

    T sum(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret += bit[k];
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] += x;
    }
    
    T lower_bound(T x){
        int i = 0;
        for (int j = m; j > 0; j >>= 1) {
            if(i+j < bit.size() && bit[i+j] < x) x -= bit[i += j];
        }
        return i;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> idx(n);
    vector<int> a(n);
    BIT<int> S(n);

    for (int i = 0; i < n; ++i) {
        S.add(i, 1);
    }
    for (int i = n-1; i >= 0; --i) {
        idx[i] = S.lower_bound(v[i]+1);
        S.add(idx[i], -1);
        a[n-idx[i]-1] = i;
    }
    vector<int> x(n, INF<int>);
    for (int i = 0; i < n; ++i) {
        int c = lower_bound(x.begin(),x.end(), a[i])-x.begin();
        x[c] = min(x[c], a[i]);
    }
    cout << lower_bound(x.begin(),x.end(), INF<int>-1) - x.begin() << "\n";
    return 0;
}