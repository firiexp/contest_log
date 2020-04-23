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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v(2, vector<int> (n, 0));
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        r--; c--;
        int rr = r^1;
        int sign = (v[r][c] ? -1 : 1);
        for (int j = -1; j <= 1; ++j) {
            if(0 <= c + j && c + j < n){
                cnt += sign * v[rr][c+j];
            }
        }
        v[r][c] ^= 1;
        puts(cnt ? "No" : "Yes");
    }
    return 0;
}