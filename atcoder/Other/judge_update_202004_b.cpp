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
    for (int i = 0; i < n; ++i) {
        int a; char b;
        cin >> a >> b;
        if(b == 'B') a += 100000;
        v[i] = a;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        printf("%d\n", v[i]%100000);
    }
    return 0;
}