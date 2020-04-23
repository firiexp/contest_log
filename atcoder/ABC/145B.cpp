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
    cin >> n >>  s;
    if(n%2) puts("No");
    else {
        if(s.substr(0, s.size()/2) == s.substr(s.size()/2, s.size()/2)){
            puts("Yes");
        }else {
            puts("No");
        }
    }
    return 0;
}