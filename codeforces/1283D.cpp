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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    map<int, int> S;
    for (int i = 0; i < n; ++i) S[v[i]]++;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; j += 2) {
            if(!S.count(v[i]+j)){
                Q.emplace(v[i]+j, 1);
                S[v[i]+j]++;
            }
        }
    }
    ll ans = 0;
    vector<int> anss;
    for (int i = 0; i < m; ++i) {
        int a, val; tie(a, val) = Q.front(); Q.pop();
        anss.emplace_back(a);
        ans += val;
        for (int j = -1; j <= 1; j += 2) {
            if(!S.count(a+j)){
                Q.emplace(a+j, val+1);
                S[a+j]++;
            }
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < m; ++i) {
        if(i) printf(" ");
        printf("%d", anss[i]);
    }
    puts("");
    return 0;
}