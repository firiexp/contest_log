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
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = {x, i};
    }
    sort(v.begin(),v.end());
    int ans = 0;
    vector<int> ans2(n);
    queue<pair<int, int>> Q;
    vector<int> e;
    for (int i = 0; i < n; ++i) {
        while(!Q.empty() && Q.front().first + d < v[i].first){
            e.emplace_back(Q.front().second);
            Q.pop();
        }
        if(e.empty()){
            ans2[v[i].second] = ++ans;
            Q.emplace(v[i].first, ans);
        }else {
            ans2[v[i].second] = e.back();
            Q.emplace(v[i].first, e.back());
            e.pop_back();
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans2[i]);
    }
    puts("");
    return 0;
}