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
    string s, t;
    cin >> s >> t;
    map<char, char> m1, m2;
    for (int i = 0; i < s.length(); ++i) {
        if(m1[s[i]] == 0) m1[s[i]] = t[i];
        else if(m1[s[i]] != t[i]) {
            cout << "No" << "\n";
            return 0;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if(m2[t[i]] == 0) m2[t[i]] = s[i];
        else if(m2[t[i]] != s[i]) {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
