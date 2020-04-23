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
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a-1]++;
        cnt[b-1]++;
    }
    ll c = 0;
    for (int i = 0; i < n; ++i) {
        if(cnt[i] == 1) c++;
    }
    if(c*(c-1)/2 >= n || n == 2){
        puts("YES");
    }else {
        puts("NO");
    }
    return 0;
}