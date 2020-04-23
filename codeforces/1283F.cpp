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

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n;
    cin >> n;
    vector<int> v(n-1);
    for (auto &&i : v) scanf("%d", &i);
    vector<int> cnt(n), val(n);
    for (int i = 0; i < n-1; ++i) {
        v[i]--;
        cnt[v[i]]++;
    }
    GPQ<pair<int, int>> Q; // max, 親
    for (int i = 0; i < n; ++i) {
        if(!cnt[i]){
            Q.emplace(i, i);
        }
        val[i] = i;
    }
    vector<int> ans1, ans2;
    int ans = v[0];
    for (int i = n-2; i >= 0; --i) {
        if(Q.empty()){
            puts("-1");
            return 0;
        }
        auto P = Q.top(); Q.pop();
        ans1.emplace_back(v[i]+1);
        ans2.emplace_back(P.second+1);
        cnt[v[i]]--;
        if(!cnt[v[i]]){
            Q.emplace(max(v[i], P.first), v[i]);
        }
    }
    if(Q.size() != 1){
        puts("-1");
        return 0;
    }
    printf("%d\n", Q.top().second+1);
    for (int i = 0; i < n-1; ++i) {
        printf("%d %d\n", ans1[i], ans2[i]);
    }
    return 0;
}