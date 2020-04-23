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

void solve(){
    int n;
    cin >> n;
    vector<int> ls(n), rs(n);
    vector<pair<int, int>> query(2*n);
    vector<int> val;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &ls[i], &rs[i]);
        query[i] = {ls[i], i}; query[i+n] = {rs[i], i+n};
    }
    sort(query.begin(),query.end());
    set<int> s;
    int cur = 0, cnt = 0;
    int ans = 1;
    vector<vector<int>> A(n);
    while(cur < 2*n){
        int curr = cur;
        while(curr < 2*n && query[cur].first == query[curr].first){
            if(query[curr].second >= n){
                s.erase(query[curr].second);
            }else s.emplace(query[curr].second);
            curr++;
        }
        val.emplace_back(s.size());
        if(curr != 2*n && s.empty()){
            ans++;
        }
        if(s.size() == 1){
            int x = *s.begin();
            A[x].emplace_back(cnt);
        }
        cur = curr;
        cnt++;
    }
    int ans2 = 0;
    for (int i = 0; i < n; ++i) {
        int vala = 0;
        for (auto &&j : A[i]) {
            if(j != 0 && val[j-1] >= 2 && val[j+1] >= 2) vala++;
            if(j == 0 && val[j+1] == 0) vala--;
            if(j != 0 && val[j-1] == 0 && val[j+1] == 0) vala--;
        }
        ans2 = max(ans2, vala);
    }
    cout << ans+ans2 << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}