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
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(),v.end());
    vector<int> cnt(n+2);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(!cnt[v[i]+j]){
                cnt[v[i]+j] = 1;
                ans2++;
                break;
            }
        }
    }
    int cur = 0;
    while(cur < n){
        int curr = cur;
        while(curr < n && v[cur]+2 >= v[curr]){
            curr++;
        }
        ans1++;
        cur = curr;
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}