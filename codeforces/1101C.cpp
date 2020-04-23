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
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int n;
        scanf("%d", &n);
        vector<tuple<int, int, int>> v;
        for (int j = 0; j < n; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            v.emplace_back(a, b, j);
        }
        vector<int> ans(n, 0);
        sort(v.begin(), v.end());
        int x = -1;
        int q = 0;
        for (int j = 0; j < n; ++j) {
            int a, b, t;
            tie(a, b, t) = v[j];
            if(j != 0 && x < a) {
                q = 1;
                break;
            }
            x = max(x, b);
            ans[t] = 1;
        }
        if(!q) puts("-1");
        else {
            for (int j = 0; j < n; ++j) {
                if(j) printf(" ");
                printf("%d", ans[j]+1);
            }
            printf("\n");
        }
    }
    return 0;
}
