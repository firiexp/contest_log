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

using P = pair<int, int>;
P gcd(P a, P b){
    if(b == make_pair(0, 0)) return a;
    P c = {a.first%b.first, };
}


int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a*d == b*c){
        if(a*d == 0) {

        }
    }
    return 0;
}