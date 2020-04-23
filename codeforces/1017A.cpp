#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d%d%d%d",&a, &b, &c, &d);
        v.emplace_back(a+b+c+d);
        if(i == 0) p = a+b+c+d;
    }
    sort(v.begin(), v.end(),greater<>());
    cout << lower_bound(v.begin(), v.end(), p, greater<>()) - v.begin()+1 << "\n";
    return 0;
}
