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
    while(cin >> s){
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '@') {
                ans += string(s[i+1]-'0', s[i+2]);
                i += 2;
            }else {
                ans += s[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}