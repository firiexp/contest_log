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

bool is_parindrome(const string &s, char c = '?'){
    auto n = s.length();
    for (int i = 0; i < (n+1)/2; ++i) {
        if(s[i] == c || s[n-i-1] == c) continue;
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (is_parindrome(s, '*') ? "YES\n" : "NO\n");
    return 0;
}
