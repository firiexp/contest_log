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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int ok = 0;
        sort(v.begin(),v.end());
        for (int i = 0; i < n-1; ++i) {
            if(v[i]+1 == v[i+1]) ok = 1;
        }
        printf("%d\n", ok+1);
    }
    return 0;
}