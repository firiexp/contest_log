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

int solve(int a, int k){
    while(a%k && a >= k){
        int d = (a+k-1)/k;
        int to = a/k*k;
        a = to-((to-a)%d+d)%d;
    }
    return a/k;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a, k;
        cin >> a >> k;
        ans ^= solve(a, k);
    }
    puts(ans ? "Takahashi" : "Aoki");
    return 0;
}