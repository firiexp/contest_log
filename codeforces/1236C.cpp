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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if(i & 1){
            for (int j = 0; j < n; ++j) {
                v[j][i] = cnt++;
            }
        }else {
            for (int j = n - 1; j >= 0; --j) {
                v[j][i] = cnt++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j) printf(" ");
            printf("%d", v[i][j]);
        }
        puts("");
    }
    return 0;
}