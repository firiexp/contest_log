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
    vector<int> v(4);
    for (auto &&i : v) scanf("%d", &i);
    int mn = min_element(v.begin(),v.end()) - v.begin();
    cout << "50 50" << "\n";
    array<array<char, 50>, 50> ans{};
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            ans[i][j] = 'A' + mn;
        }
    }
    int cur = mn == 0;
    for (int i = 0; i < v[mn]-1; ++i) {
        int y = i/25*2, x = i%25*2;
        ans[y][x+1] = ans[y+1][x] = ans[y+1][x+1] = 'A' + cur;
        v[cur]--;
        cur = (cur+1)%4;
        if(cur == mn) cur = (cur+1)%4;
    }
    cur = v[mn]-1;
    for (int c = 0; c < 4; ++c) {
        if(mn == c) continue;
        for (int i = 0; i < v[c]; ++i) {
            int y = cur/25*2, x = cur%25*2;
            ans[y+1][x+1] = 'A' + c;
            cur++;
        }
    }
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            printf("%c", ans[i][j]);
        }
        puts("");
    }
    return 0;
}