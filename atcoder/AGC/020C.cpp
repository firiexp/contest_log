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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    bitset<4000001> b;
    b.set(0);
    for (int i = 0; i < n; ++i) {
        b |= b << v[i];
    }
    int x = b.count(), cnt = 0;
    for (int i = 1; i < 4000001; ++i) {
        if(b[i]){
            if(cnt == (x-2)/2){
                cout << i << "\n";
                return 0;
            }
            cnt++;
        }
    }
    return 0;
}
