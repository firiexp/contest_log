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
    int n, t; cin >> n >> t;
    string s;
    cin >> s;
    for (int i = 0; i < t; ++i) {
        string t = s;
        for (int j = n - 2; j >= 0; --j) {
            if(s[j] == 'B' && s[j+1] == 'G'){
                swap(t[j], t[j+1]);
            }
        }
        s = t;
    }
    cout << s << "\n";
    return 0;
}