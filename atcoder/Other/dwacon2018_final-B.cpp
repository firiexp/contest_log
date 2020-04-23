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
template<class T>
class BIT {
    vector<T> bit;


public:
    BIT(int n): bit(vector<T>(n+1, 0)){}

    T max(int k){
        T ret = 0;
        for (++k; k > 0; k -= (k & -k)) ret = std::max(ret, bit[k]);
        return ret;
    }

    void add(int k, T x){
        for (++k; k < bit.size(); k  += (k & -k)) bit[k] = std::max(bit[k], x);
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    BIT<int> s(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = {x, -i};
    }
    sort(v.begin(),v.end());
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            s.add(-v[j].second, s.max(-v[j].second-1)+1);
        }
    }
    cout << s.max(n-1) << "\n";
    return 0;
}