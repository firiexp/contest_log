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
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(),v.end());
    n = v.size();
    int ans = v.front();
    for (int i = 0; i+1 < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(v[i]%v[j] != 0){
                ans = max(ans, v[i]+v[j]);
                break;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if(v[0]%v[i] == 0) continue;
        for (int j = i+1; j < n; ++j) {
            if(v[0]%v[j] == 0 || v[i]%v[j] == 0) continue;
            if(ans < v[0]+v[i]+v[j]) ans = v[0]+v[i]+v[j];
            break;
        }
    }
    set<int> s(v.begin(),v.end());
    if(v.front()%30 == 0 && s.count(v.front()/2) && s.count(v.front()/3) && s.count(v.front()/5)){
        ans = max(ans, v.front()*31/30);
    }
    cout << ans << "\n";
}

int main() {
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}