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
    array<int, 3> ar{};
    for (int i = 0; i < 3; ++i) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    cout << max(0, ar[2]-ar[1]-ar[0]+1) << "\n";
    return 0;
}
