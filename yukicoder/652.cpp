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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b; string s;
    cin >> a >> b >> s;
    int tt = static_cast<int>(round(stold(s.substr(3, 1000)) * 60));
    int t = (a*60+b+tt+13860)%1440;
    printf("%02d:%02d\n", t/60, t%60);
    return 0;
}
