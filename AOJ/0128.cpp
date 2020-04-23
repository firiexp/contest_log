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
    vector<string> values = {
            "* = ****",
            "* =* ***",
            "* =** **",
            "* =*** *",
            "* =**** ",
            " *= ****",
            " *=* ***",
            " *=** **",
            " *=*** *",
            " *=**** "
    };
    int n, a = 0;
    while(cin >> n){
        if(a++) puts("");
        vector<string> ans(5);
        for (int i = 4; i >= 0; --i) {
            ans[i] = values[n%10];
            n /= 10;
        }
        for (int i = 0; i < ans[0].size(); ++i) {
            for (int j = 0; j < ans.size(); ++j) {
                printf("%c", ans[j][i]);
            }
            puts("");
        }
    }
    return 0;
}