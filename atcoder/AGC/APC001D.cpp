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


class UnionFind {
    vector<int> uni;
    int n;
public:
    explicit UnionFind(int n) : uni(static_cast<u32>(n), -1) , n(n){};

    int root(int a){
        if (uni[a] < 0) return a;
        else return (uni[a] = root(uni[a]));
    }

    bool unite(int a, int b) {
        a = root(a);
        b = root(b);
        if(a == b) return false;
        if(uni[a] > uni[b]) swap(a, b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    if(m == n-1){
        puts("0");
        return 0;
    }else if(n > 2*m+2){
        puts("Impossible");
        return 0;
    }
    vector<int> v(n);
    for (auto &&item : v) scanf("%d", &item);
    UnionFind uni(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        uni.unite(a, b);
    }
    map<int, vector<int>> x;
    for (int i = 0; i < n; ++i) {
        x[uni.root(i)].emplace_back(v[i]);
    }
    vector<int> u;
    ll ans = 0, y = 0;
    for (auto &&i : x) {
        sort(i.second.begin(), i.second.end());
        for (int j = 0; j < i.second.size(); ++j) {
            if(j == 0) ans += i.second[j], y++;
            else u.emplace_back(i.second[j]);
        }
    }
    sort(u.begin(), u.end());
    int i = 0;
    while(i+y < 2*(n-m-1)){
        ans += u[i++];
    }
    cout << ans << "\n";
    return 0;
}
