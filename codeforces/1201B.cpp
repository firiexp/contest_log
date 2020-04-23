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
    vector<int> v(n);
    ll S = 0, M = 0;
    for (auto &&i : v) scanf("%d", &i), S += i, M = max<ll>(M, i);
    if(S%2 || S < 2*M){
        puts("NO");
    }else {
        puts("YES");
    }
    return 0;
}