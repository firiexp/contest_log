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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n);
    int p = 0;
    int r = 0;
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'R' && s[i+1] == 'L'){
            int l = i+1;
            while(l < n && s[l+1] == 'L') l++;
            for (int j = r; j <= l; ++j) {
                if(j%2 == i%2) ans[i]++;
                else ans[i+1]++;
            }
            r = l+1;
            i = l;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}