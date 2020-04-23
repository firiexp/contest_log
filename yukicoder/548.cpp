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
    sort(s.begin(), s.end());
    if(s == "abcdefghijklm"){
        for (char i = 'a'; i <= 'm'; ++i) {
            cout << i << "\n";
        }
        return 0;
    }
    map<char, int> m;
    for (auto &&i : s) m[i]++;
    vector<char> v;
    int p = 0;
    for (int i = 'a'; i <= 'm'; ++i) {
        if(m[i] == 0) v.emplace_back(i);
        else if (m[i] == 2) p++;
        if (m[i] >= 3 || p > 1){
            cout << "Impossible\n";
            return 0;
        }
    }
    for (char i = 'n'; i <= 'z'; ++i) {
        if(m[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << v[0] << "\n";
    return 0;
}

