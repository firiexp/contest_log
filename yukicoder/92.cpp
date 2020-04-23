#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <typename T>
struct edge {
    int from, to;
    T cost;

    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

    explicit operator int() const {return to;}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bitset<101>> v(2);
    v[0].set();
    vector<edge<int>> e;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e.emplace_back(a-1, b-1, c);
    }
    for (int i = 0; i < k; ++i) {
        int now = i&1, nxt = now^1;
        v[nxt].reset();
        int x;
        cin >> x;
        for (int j = 0; j < m; ++j) {
            if(e[j].cost == x){
                v[nxt][e[j].to] = v[nxt][e[j].to]|v[now][e[j].from];
                v[nxt][e[j].from] = v[nxt][e[j].from]|v[now][e[j].to];
            }
        }
    }
    cout << v[k&1].count() << "\n";
    for (int i = 0; i < n; ++i) {
        if(v[k&1][i]) cout << i+1 << " ";
    }
    cout << "\n";
    return 0;
}
