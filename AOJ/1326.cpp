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
void solve(int p, int q){
    vector<string> v(p), u(q);
    for (auto &&i : v) cin >> i;
    for (auto &&i : u) cin >> i;
    vector<int> ans(q, -2);
    for (int R = 1; R <= 20; ++R) {
        for (int C = 1; C <= 20; ++C) {
            for (int S = 1; S <= 20; ++S) {
                int cnt1 = 0, cnt2 = 0, cnt3 = 0;
                int ok = 1;
                for (int i = 0; i < p; ++i) {
                    int x = 0;
                    for (auto &&j : v[i]) {
                        if(j == '.') x++;
                        else break;
                    }
                    if(x != R*cnt1+C*cnt2+S*cnt3){
                        ok = 0;
                        break;
                    }
                    for (auto &&j : v[i]) {
                        if(j == '(') cnt1++;
                        if(j == ')') cnt1--;
                        if(j == '{') cnt2++;
                        if(j == '}') cnt2--;
                        if(j == '[') cnt3++;
                        if(j == ']') cnt3--;
                    }
                }
                if(!ok) continue;
                for (int i = 0; i < q; ++i) {
                    if(ans[i] == -2){
                        ans[i] = R*cnt1+C*cnt2+S*cnt3;
                    } else if(ans[i] != R*cnt1+C*cnt2+S*cnt3){
                        ans[i] = -1;
                    }
                    for (auto &&j : u[i]) {
                        if(j == '(') cnt1++;
                        if(j == ')') cnt1--;
                        if(j == '{') cnt2++;
                        if(j == '}') cnt2--;
                        if(j == '[') cnt3++;
                        if(j == ']') cnt3--;
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
}
int main() {
    int p, q;
    while(cin >> p >> q, p){
        solve(p, q);
    }
    return 0;
}