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
    ll n, m;
    cin >> n >> m;
    auto teams = [](ll x){ return x*(x-1)/2; };
    cout << (n%m)*teams(n/m+1)+(m-n%m)*teams(n/m) << " " <<
            teams(n-m+1) << "\n";
    return 0;
}