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
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(s == "black") a++;
        else b++;
    }
    if(a > b) puts("black");
    else puts("white");
    return 0;
}