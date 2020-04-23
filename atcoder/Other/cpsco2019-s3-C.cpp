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
    array<int, 1000010> v{};
    for (int i = 0; i < n; ++i) {
        int s, t;
        cin >> s >> t;
        v[s-1]++;
        v[t-1]--;
    }
    int cur = 0, ans = 0;
    for (int i = 0; i < 1000005; ++i) {
        v[i+1] += v[i];
    }
    while(cur < 1000010){
        if(v[cur]){
            while(v[cur+1]) cur++;
            ans++;
        }
        cur++;
    }
    cout << ans << "\n";
    return 0;
}