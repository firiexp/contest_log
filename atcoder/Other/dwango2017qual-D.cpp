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

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;
int main() {
    int n, m;
    cin >> n >> m;

    GPQ<int> Q;
    int ans = 0, S = 0, S2 = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        S += y;
        chmax(ans, S + S2 + (x-y));
        Q.emplace(x-y); S2 += (x-y);
        if(Q.size() == m) {
            S2 -= Q.top();
            Q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
