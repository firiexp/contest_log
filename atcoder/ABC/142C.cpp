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
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = {x, i};
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        if(i) printf(" ");
        printf("%d", v[i].second+1);
    }
    puts("");
    return 0;
}