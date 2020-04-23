#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    cin >> s;
    vector<int> v(s.size());
    vector<int> u, u2;
    for (int i = 0; i+1 < s.size(); ++i) {
        if(s[i] == 'A' && s[i+1] == 'B') u.emplace_back(i);
        if(s[i] == 'B' && s[i+1] == 'A') u2.emplace_back(i);
    }
    for (auto &&i : u) {
        for (auto &&j : u2) {
            if(abs(i-j) > 1) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
