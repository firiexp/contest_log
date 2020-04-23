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
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i+1; j < s.size(); ++j) {
            string t;
            if(s[i] != '(' || s[j] != ')') continue;
            int cnt = 0,  valid = 1, stars = 0;
            for (int k = i; k <= j; ++k) {
                if(s[k] == '(') cnt++;
                else if(s[k] == ')') cnt--;
                else stars++;
                if(cnt <= 0) {
                    if(stars) stars = 0;
                    else valid = 0;
                }
                t += s[k];
            }
            if(cnt == 0 && valid) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}