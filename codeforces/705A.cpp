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
    int n;
    cin >> n;
    stringstream ans;
    for (int i = 0; i < n; ++i) {
        if(i) ans << " that ";
        ans << "I";
        if(i%2) ans << " love";
        else ans << " hate";
    }
    ans << " it";
    cout << ans.str() << "\n";
    return 0;
}
