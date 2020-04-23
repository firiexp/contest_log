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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    int minval = INF<int>, minidx = -1;
    vector<int> v2(v);
    for (int i = 0; i < n; ++i) {
        v2[i] -= i;
        if(minval < v2[i]){
            puts("YES");
            cout << minidx+1 << " " << i+1 << "\n";
            return;
        }
        if(minval > v2[i]){
            minval = v2[i];
            minidx = i;
        }
    }
    minval = INF<int>, minidx = -1;
    for (int i = n-1; i >= 0; --i) {
        v[i] += i;
        if(minval < v[i]){
            puts("YES");
            cout << i+1 << " " << minidx+1 << "\n";
            return;
        }
        if(minval > v[i]){
            minval = v[i];
            minidx = i;
        }
    }

    puts("NO");
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}