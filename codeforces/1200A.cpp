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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans(10, '0');
    for (auto &&i : s) {
        if(i == 'L'){
            for (int j = 0; j < 10; ++j) {
                if(ans[j] == '0') {
                    ans[j] = '1';
                    break;
                }
            }
        }else if(i == 'R') {
            for (int j = 9; j >= 0; --j) {
                if(ans[j] == '0') {
                    ans[j] = '1';
                    break;
                }
            }
        }else {
            ans[i-'0'] = '0';
        }
    }
    cout << ans << "\n";
    return 0;
}