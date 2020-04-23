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
    int t, h, s;
    while(cin >> t >> h >> s, ~t){
        int rem = 7200-t*3600-h*60-s;
        printf("%02d:%02d:%02d\n", rem/3600, rem%3600/60, rem%60);
        rem *= 3;
        printf("%02d:%02d:%02d\n", rem/3600, rem%3600/60, rem%60);
    }
    return 0;
}