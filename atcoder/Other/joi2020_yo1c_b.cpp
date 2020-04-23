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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i+2 < n; ++i) {
        if(s[i] == 'j' && s[i+1] == 'o' && s[i+2] == 'i'){
            s[i] = 'J';
            s[i+1] = 'O';
            s[i+2] = 'I';
        }
    }
    cout << s << "\n";
    return 0;
}