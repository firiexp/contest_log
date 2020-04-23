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

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'O') s[i] = 'A';
        else if(s[i] == 'A') s[i] = 'O';
    }
    cout << s << "\n";
    return 0;
}