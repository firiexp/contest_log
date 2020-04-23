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

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> matched(3*n);
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        if(!matched[l] && !matched[r]){
            v.emplace_back(i+1);
            matched[l] = matched[r] = 1;
        }
    }
    if(v.size() >= n){
        puts("Matching");
        for (int i = 0; i < n; ++i) {
            if(i) printf(" ");
            printf("%d", v[i]);
        }
        puts("");
    }else {
        puts("IndSet");
        int cnt = 0;
        for (int i = 0; i < 3*n && cnt < n; ++i) {
            if(!matched[i]){
                if(cnt) printf(" ");
                printf("%d", i+1);
                cnt++;
            }
        }
        puts("");
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}