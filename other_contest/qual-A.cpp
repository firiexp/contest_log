#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int solve(string &n){
    string ans1 = n, ans2(n.size(), '0');
    for (int i = 0; i < ans1.size(); ++i) {
        if(ans1[i] == '4'){
            ans1[i]--;
            ans2[i]++;
        }
    }
    int valid = 0;
    for (auto &&j : ans1) {
        if(j != '0') valid = 1;
        if(valid) cout << j;
    }
    valid = 0;
    cout << " ";
    for (auto &&j : ans2) {
        if(j != '0') valid = 1;
        if(valid) cout << j;
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
