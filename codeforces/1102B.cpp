#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int k, n;
    cin >> n >> k;
    map<int, map<int, int>> m;
    vector<int> ans;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        int d = c;
        c = (c+1)%k;
        while(m[x][c]){
            if(c == d) {
                puts("NO");
                return 0;
            }
            c = (c+1)%k;
        }
        m[x][c]++;
        ans.emplace_back(c);
    }
    puts("YES");
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");
    return 0;
}
