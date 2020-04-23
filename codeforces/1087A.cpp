#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    string s, ans;
    cin >> s;
    if(s.size()%2) {

        ans += s[s.size()/2];
        s = s.substr(0, s.size()/2) + s.substr(s.size()/2+1, s.size()/2);
        reverse(s.begin(), s.end());
    }

    for (int i = 0; i < s.size()/2; ++i) {
        ans += s[s.size()/2-i-1];
        ans += s[s.size()/2+i];
    }
    cout << ans << "\n";
    return 0;
}
