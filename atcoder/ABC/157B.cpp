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

int dp[3][3], ok[3][3];
int cnt1[3], cnt2[3], cnt3[2];
int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
            ok[i][j] = 0;
            cnt1[i] = 0;
            cnt2[j] = 0;
        }
    }
    cnt3[0] = cnt3[1] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(x == dp[j][k] && !ok[j][k]) {
                    cnt1[j]++;
                    cnt2[k]++;
                    if(j == k) cnt3[0]++;
                    if(j == 2-k) cnt3[1]++;
                    ok[j][k] = 1;
                }
            }
        }
    }
    if(*max_element(cnt1, cnt1+3) == 3 || *max_element(cnt2, cnt2+3) == 3 || *max_element(cnt3, cnt3+2) == 3) puts("Yes");
    else puts("No");

    return 0;
}