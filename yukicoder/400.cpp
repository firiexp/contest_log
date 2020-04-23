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
    string s, t;
    cin >> s;
    for (int i = s.length()-1; i >= 0; --i) {
        if(s[i] == '<') t += '>';
        else t += '<';
    }
    cout << t << "\n";
    return 0;
}
