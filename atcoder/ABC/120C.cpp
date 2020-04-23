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
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '0') a++;
        else b++;
    }
    cout << (ll)s.size()-abs(b-a) << "\n";
    return 0;
}
