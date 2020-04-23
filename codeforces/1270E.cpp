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
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    while(true){
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if((xs[i]+ys[i])&1) cnt++;
        }
        if(cnt != 0 && cnt != n) break;
        for (int i = 0; i < n; ++i) {
            int x = xs[i], y = ys[i];
            if(cnt == 0) xs[i] = (x+y)/2, ys[i] = (x-y)/2;
            else xs[i] = (x+y+1)/2, ys[i] = (x-y+1)/2;
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if((xs[i]+ys[i])&1) ans.emplace_back(i+1);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}