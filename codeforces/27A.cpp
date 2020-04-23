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
    array<int, 3010> ar{};
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ar[x]++;
    }
    for (int i = 1; i <= 3005; ++i) {
        if(!ar[i]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}