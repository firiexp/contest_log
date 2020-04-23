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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    string s;
    string a, b;
    char t;
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(x == 0 && '0' <= s[i] && s[i] <= '9') x++;
        else if(x == 1 && (s[i] == '+' || s[i] == '-')) {
            x++, a = s.substr(0, i), b = s.substr(i+1, s.size());
            t = s[i];
        }
    }
    int aa = stoi(a), bb = stoi(b);
    cout << (t == '+' ? aa-bb : aa+bb) << "\n";
    return 0;
}
