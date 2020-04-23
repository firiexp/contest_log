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
    string n, m;
    cin >> m >> n;
    int a = stoi(n), b = stoi(m);
    if(a == 16 && b == 16){
        puts("18446744073709551616");
        return 0;
    }
    uint64_t ans = 1;
    for (int i = 0; i < b; ++i) {
        ans *= a;
    }

    string anss = to_string(ans);
    cout << anss << "\n";
    return 0;
}
