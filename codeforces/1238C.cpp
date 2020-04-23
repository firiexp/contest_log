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
    int q;
    cin >> q;
    while(q--){
        int h, n;
        cin >> h >> n;
        vector<int> v(n);
        for (auto &&i : v) scanf("%d", &i);
        int cur = 1, ans = 0;
        v.emplace_back(0);
        while(cur < n){
            int nxt = cur;
            while(nxt < n && v[nxt]-v[nxt+1] == 1) nxt++;
            if((nxt-cur+1)&1 && nxt != n) ans++;
            cur = nxt+1;
        }
        printf("%d\n", ans);
    }

    return 0;
}