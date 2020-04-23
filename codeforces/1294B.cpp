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
    vector<pair<int, int>> v(n+1);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(),v.end());
    string ans;
    for (int i = 0; i < n; ++i) {
        if(v[i].second > v[i+1].second){
            puts("NO");
            return;
        }
        ans += string(v[i+1].first-v[i].first, 'R');
        ans += string(v[i+1].second-v[i].second, 'U');
    }
    puts("YES");
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}