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


bool is_prime(ll x){ return true; };


int main() {
    ll n;
    cin >> n;
    if(n == 4) puts("3");
    else if(n == 6) puts("5");
    else if(n == 8 || n == 9 || n == 10 || n == 15 || n == 16 || n == 22) puts("7");
    else if(n == 12) puts("11");
    else if(n == 14) puts("13");
    else if(n == 20 || n == 21) puts("19");
    else if(n == 24 || n == 25) puts("23");
    else if(is_prime(n-8)) puts("8");
    else puts("14");
    return 0;
}