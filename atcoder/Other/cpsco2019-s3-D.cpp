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
    int n;
    string s;
    cin >> n >> s;
    if(s.front() != 'R' || s.back() != 'B'){
        puts("No");
        return 0;
    }
    int ok = 1;
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'R' && s[i+1] == 'B') ok = 0;
        if(s[i] == 'G' && s[i+1] == 'G') ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}