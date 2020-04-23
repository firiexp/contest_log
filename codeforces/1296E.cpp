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
    int n; string s;
    cin >> n >> s;
    multiset<pair<int, int>> S;
    S.emplace(-1, 1);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        auto x = S.upper_bound({s[i]+1, 0});
        if(x == S.begin()){
            int xx = S.size()+1;
            S.emplace(s[i], xx);
            ans[i] = xx;
        }else {
            x--;
            int q = x->second;
            S.erase(x);
            S.emplace(s[i], q);
            ans[i] = q;
        }
    }
    if(S.size() > 2){
        puts("NO");
        return 0;
    }else {
        puts("YES");
    }
    for (int i = 0; i < n; ++i) {
        printf("%d", ans[i]-1);
    }
    puts("");
    return 0;
}