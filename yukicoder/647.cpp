#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = make_pair(a, b);
    }
    int m, ma = 0;
    cin >> m;
    vector<int> cnt(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        int c = 0;
        for (int j = 0; j < n; ++j) {
            int a, b;
            tie(a, b) = v[j];
            if(x <= a && y >= b) c++;
        }
        cnt[i] = c;
        ma = max(c, ma);
    }
    if(ma == 0){
        puts("0");
        return 0;
    }else {
        for (int i = 0; i < m; ++i) {
            if(ma == cnt[i]) printf("%d\n", i+1);
        }
    }
    return 0;
}
