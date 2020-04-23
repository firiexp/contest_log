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
    int cur = 0;
    int a = 1-n%2;
    for (int i = 0; i < n/2; ++i) {
        if(s[i] == s[n-i-1]) cur++;
        else break;
    }
    if(cur == n/2){
        cout << s.substr(0, n/2) + s[n/2]+s.substr(n/2, n);
        return 0;
    }
    string p = s.substr(0, cur) + s[n-cur-1]+ s.substr(cur, n);
    string q = s.substr(0, n-cur) + s[cur] + s.substr(n-cur, n);
    if(is_parindrome(p)) cout << p << "\n";
    else if(is_parindrome(q)) cout << q << "\n";
    else cout << "NA" << "\n";
    return 0;
}