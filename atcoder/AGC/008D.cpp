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
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> ans(n*n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v.emplace_back(x-1, i+1);
        ans[x-1] = i+1;
    }
    sort(v.begin(),v.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].second-1; ++j) {
            while(ans[cur] != 0){
                if(cur >= v[i].first){
                    puts("No");
                    return 0;
                }
                cur++;
            }
            ans[cur] = v[i].second;
        }
    }
    cur = n*n-1;
    reverse(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-v[i].second; ++j) {
            while(ans[cur] != 0){
                if(cur <= v[i].first){
                    puts("No");
                    return 0;
                }
                cur--;
            }
            ans[cur] = v[i].second;
        }
    }
    puts("Yes");
    for (int i = 0; i < n*n; ++i) {
        if(i) cout << " ";
        cout << ans[i];
    }
    puts("");
    return 0;
}