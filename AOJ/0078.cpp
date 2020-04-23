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

void solve(int n){
    vector<vector<int>> v(n, vector<int>(n, 0));
    int y = n/2+1, x = n/2;
    int cnt = 1;
    while(cnt <= n*n){
        v[y][x] = cnt++;
        int yy = (y+1)%n, xx = (x+1)%n;
        if(v[yy][xx]) yy = (yy+1)%n, xx = (xx+n-1)%n;
        y = yy, x = xx;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%4d", v[i][j]);
        }
        puts("");
    }
}

int main() {
    int n;
    while(cin >> n, n){
        solve(n);
    }
    return 0;
}