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
    int n, q;
    cin >> n >> q;
    BIT<int> S(n+1);
    for (int i = 0; i < q; ++i) {
        int c;
        scanf("%d", &c);
        if(c == 0){
            int s, t, x;
            scanf("%d %d %d", &s, &t, &x);
            S.add(s-1, x);
            S.add(t, -x);
        }else {
            int x;
            scanf("%d", &x);
            printf("%d\n", S.sum(x-1));
        }
    }
    return 0;
}