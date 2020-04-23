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

int main() {
    vector<vector<int>> v(8);
    v[0] = {1, 4, 1, 4, 1, 2, 1, 2};
    for (int i = 1; i < 8; ++i) {
        v[i] = v[i-1];
        rotate(v[i].begin(), v[i].begin()+1, v[i].end());
    }
    sort(v.begin(),v.end());
    vector<int> a(8);
    while(scanf("%d", &a[0]) != EOF){
        for (int i = 1; i < 8; ++i) scanf("%d", &a[i]);
        int ans = 0, val = INF<int>;
        for (int i = 0; i < 8; ++i) {
            int p = 0;
            for (int j = 0; j < 8; ++j) {
                p += max(0, a[j]-v[i][j]);
            }
            if(p < val) ans = i, val = p;
        }
        for (int i = 0; i < 8; ++i) {
            if(i) printf(" ");
            printf("%d", v[ans][i]);
        }
        puts("");
    }
    return 0;
}