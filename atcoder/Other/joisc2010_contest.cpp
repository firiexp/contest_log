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

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }


int main() {
    int n, m, t, x, Q;
    cin >> n >> m >> t >> x >> Q;
    vector<int> tasks(m);
    for (auto &&i : tasks) scanf("%d", &i);
    vector<int> point(n, 0);
    auto open = make_v(n, m, 0);
    auto penalty = open;
    for (int i = 0; i < Q; ++i) {
        int T, p, q;
        string s;
        cin >> T >> p >> q >> s;
        if(s == "open") open[p-1][q-1] = T;
        else if(s == "incorrect") penalty[p-1][q-1]++;
        else point[p-1] += max(x, tasks[q-1]-(T-open[p-1][q-1])-120*penalty[p-1][q-1]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", point[i]);
    }
    return 0;
}
