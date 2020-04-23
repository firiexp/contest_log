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
    vector<int> v(1 << (n+1));
    for (int i = 0; i < 1 << n; ++i) {
        scanf("%d", &v[i+(1 << n)]);
    }
    for (int i = (1 << n)-1; i >= 1; --i) {
        int l = (i << 1), r = (i << 1) | 1;
        if(v[l] != v[r]) v[i] = abs(v[l]-v[r]);
        else v[i] = v[l];
    }
    cout << v[1] << "\n";
    return 0;
}