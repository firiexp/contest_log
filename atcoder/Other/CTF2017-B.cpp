#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

bool is_parindrome(const string &s){
    u32 n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] == '?' || s[n-i-1] == '?') continue;
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int ans = 0;
    if(s.length() > 1) for (u32 i = 0; i < s.length(); ++i) {
        string t = s + string(i, '?');
        if(is_parindrome(t)) {ans = i; break;}
    }
    cout << ans << "\n";
    return 0;
}
