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

vector<vector<int>> ans;

void rec(int l, int r, int depth){
    if(abs(l-r) <= 1) {
        return;
    }
    int m = (l+r)/2;
    rec(l, m, depth+1); rec(m, r, depth+1);

    for (int i = 0; i < m; ++i) {
        for (int j = m; j < r; ++j) {
            ans[j][i] = depth;
            ans[i][j] = depth;
        }
    }
}

int main() {
    int n;
    cin >> n;
    ans = vector<vector<int>> (n, vector<int>(n, -1));
    rec(0, n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(j != i+1) printf(" ");
            printf("%d", ans[i][j]);
        }
        puts("");
    }
    return 0;
}