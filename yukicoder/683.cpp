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


bool f(ll a, ll b){
    if(a == 0 || b == 0) return true;
    bool ans = false;
    if(!(a&1)) ans |= f(a/2, b-1);
    if(!(b&1)) ans |= f(a-1, b/2);
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    puts(f(a, b) ? "Yes" : "No");
    return 0;
}