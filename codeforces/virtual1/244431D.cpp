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
    string t;
    for (int i = 0; i < s.size(); i += 2) {
        t += s[i];
    }
    sort(t.begin(),t.end());
    for (int i = 0; i < t.size(); ++i) {
        if(i) cout << "+";
        cout << t[i];
    }
    puts("");
    return 0;
}