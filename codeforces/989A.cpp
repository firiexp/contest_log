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
    string s;
    cin >> s;
    int ok = 0;
    for (int i = 1; i+1 < s.size(); ++i) {
        int a = 0, b = 0, c = 0;
        for (int j = -1; j <= 1; ++j) {
            if(s[i+j] == 'A') a++;
            else if(s[i+j] == 'B') b++;
            else if(s[i+j] == 'C') c++;
        }
        if(a != 0 && b != 0 && c != 0) ok++;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}