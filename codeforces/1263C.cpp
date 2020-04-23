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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int t;
    cin >> t;
    int M = 35000;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 1; i <= M; ++i) {
            ans.emplace_back(n/i);
        }
        while(ans.back() > 0) ans.emplace_back(ans.back()-1);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        printf("%zu\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}