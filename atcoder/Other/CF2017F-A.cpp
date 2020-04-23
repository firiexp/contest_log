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
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    string s;
    cin >> s;
    s = "?" + s;
    for (int i = 1; i <= s.length(); ++i) {
        if((s[i] == 'K' || s[i] == 'B' || s[i] == 'R') && s[i-1] != 'A'){
            s = s.substr(0, i) + 'A' + s.substr(i, s.length()-i+1);
        }
    }
    if(s[s.length()-1] != 'A') s = s + 'A';
    if(s == "?AKIHABARA") cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
