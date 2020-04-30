#include <iostream>
#include <algorithm>
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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &&i : v) scanf("%d %d", &i.first, &i.second);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if(i) printf(" ");
        printf("%d:%02d", v[i].first, v[i].second);
    }
    puts("");
    return 0;
}