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
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 26>> cnt(n+1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            cnt[i+1][j] = cnt[i][j]+(s[i]-'a' == j);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        if(l == r){
            puts("Yes");
        }else {
            l--;
            int x = 0;
            for (int i = 0; i < 26; ++i) {
                x += (cnt[r][i] - cnt[l][i] != 0);
        }
            if(x == 1) {
                puts("No");
            } else if(x == 2){
                if(s[l]-'a' == s[r-1]-'a') puts("No");
                else puts("Yes");
            }else puts("Yes");
        }
    }
    return 0;
}