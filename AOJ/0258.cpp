#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>
#include <assert.h>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    while(cin >> n, n){
        vector<int> v(n+1);
        vector<int> a(n);
        for (auto &&i : v) scanf("%d", &i);
        int oo = 1;
        for (int i = 0; i < n; ++i) {
            if(v[i+1]-v[i] != v[1]-v[0]) oo = 0;
        }
        if(oo) exit(1);
        for (int i = 0; i <= n; ++i) {
            int cur = 0;
            for (int j = 0; j <= n; ++j) {
                if(i != j) a[cur++] = v[j];
            }
            int ok = 1;
            for (int j = 2; j < n; ++j) {
                if(a[j]-a[j-1] != a[1]-a[0]) ok = 0;
            }
            if(ok) {
                cout << v[i] << "\n";
                break;
            }
        }
    }
    return 0;
}