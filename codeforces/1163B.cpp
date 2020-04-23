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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cnt(100001);
    for (auto &&i : v) scanf("%d", &i), cnt[i]++;
    map<int, int> m;
    for (int i = 0; i < 100001; ++i) {
        if(cnt[i]) m[cnt[i]]++;
    }
    int ans = 1;
    for (int i = n-1; i >= 0; --i) {
        if(m.size() == 2){
            auto p = *m.begin(), q = *(++m.begin());
            if(p.first == 1 && q.first*q.second == i){
                ans = max(ans, i+1);
            }
            if(q.first-p.first == 1 && q.second == 1){
                ans = max(ans, i+1);
            }
        }else if(m.size() == 1 && (m.begin()->first == 1 || m.begin()->second == 1)){
            ans = max(ans, i+1);
        }
        m[cnt[v[i]]]--;
        if(m[cnt[v[i]]] == 0) m.erase(cnt[v[i]]);
        cnt[v[i]]--;
        if(cnt[v[i]]) m[cnt[v[i]]]++;
    }
    cout << ans << "\n";
    return 0;
}