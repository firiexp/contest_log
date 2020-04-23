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
    int k, n;
    cin >> k >> n;
    if(!(k&1)){
        printf("%d" , k/2);
        for (int i = 1; i < n; ++i) {
            printf(" %d", k);
        }
        puts("");
        return 0;
    }else if(k == 1) {
        for (int i = 0; i < (n+1)/2; ++i) {
            if(i) printf(" ");
            printf("1");
        }
        puts("");
        return 0;
    }
    vector<int> ans(n, (k+1)/2);
    int cnt = n/2, cur = n-1;
    while(cnt--){
        ans[cur]--;
        if(ans[cur] == 0) --cur;
        else {
            for (int j = cur+1; j < n; ++j) {
                ans[j] = k;
            }
            cur = n-1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(!ans[i]) break;
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}