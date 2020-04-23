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
    int n = s.size();
    string a = s.substr(0, n/2), b = s.substr(n/2+1, n);
    if(is_parindrome(s) && is_parindrome(a) && is_parindrome(b)) puts("Yes");
    else puts("No");
    return 0;
}