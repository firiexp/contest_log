#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cassert>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s;
    cin >> s;
    assert(s.length() <= 18);
    ll k = stoll(s);
    string ans;
    int x = 0;
    while (k){
        if(k%2){
            if(!ans.empty()) ans += "+";
            ans += "1";
            for (int i = 0; i < x; ++i) {
                ans += "*2";
            }
        }
        k/=2;
        x++;
    }
    cout << ans << "\n";
    return 0;
}
