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
int n, m;
ll k;
string s;
vector<vector<int>> g;

void solve1(){
    for (int i = 0; i < n; ++i) {
        bool ans = false;
        for (auto &&j : g[i]) {
            if(s[j] == 'B') {
                ans |= 1;
                break;
            }
        }
        puts(ans ? "First" : "Second");
    }
}

void solve2(){
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &&j : g[i]) {
            if(s[j] == 'R') v[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool ans = false;
        for (auto &&j : g[i]) {
            if(!v[j]) ans = true;
        }
        puts(ans ? "First" : "Second");
    }
}


int main() {

    cin >> n >> m >> k >> s;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[b-1].emplace_back(a-1);
        g[a-1].emplace_back(b-1);
    }
    k%2 ? solve1() : solve2();
    return 0;
}
