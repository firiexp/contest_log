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
    string s;
    cin >> s;
    int ans = 0;
    for (int j = 0; j < s.length() - 1; ++j) {
        if(s[j] == 'V' && s[j+1] == 'K') ans++;
    }
    for (int i = 0; i < s.length(); ++i) {
        string t = s;
        if(t[i] == 'V') t[i] = 'K';
        else t[i] = 'V';
        int k = 0;
        for (int j = 0; j < s.length() - 1; ++j) {
            if(t[j] == 'V' && t[j+1] == 'K') k++;
        }
        ans = max(k, ans);
    }
    cout << ans << "\n";
    return 0;
}
