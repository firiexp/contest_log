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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

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
    int n, k;
    cin >> n >> k;
    BIT<int> b(1000010);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int w;
        scanf("%d", &w);
        if(w > 0){
            if(s - b.sum(w-1) < k){
                s++;
                b.add(w, 1);
            }
        }else {
            if(b.sum(-w)-b.sum(-w-1)){
                s--;
                b.add(-w, -1);
            }
        }
    }
    cout << b.sum(1000005) << "\n";
    return 0;
}