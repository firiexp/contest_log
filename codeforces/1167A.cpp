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
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ok = 0;
        for (int i = 0; i < n-10; ++i) {
            if(s[i] == '8') ok++;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}