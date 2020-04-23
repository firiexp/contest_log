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
using ll = int64_t;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v;
    for (int i = 1; i <= min(a, b); ++i) {
        if(a%i == 0 && b%i == 0) v.emplace_back(i);
    }
    reverse(v.begin(), v.end());
    cout << v[k-1] << "\n";
    return 0;
}
