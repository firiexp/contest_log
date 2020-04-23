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
    vector<int> v(5);
    for (auto &&i : v) scanf("%d", &i);
    sort(v.begin(), v.end());
    int ret = INF<int>;
    do {
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            if(ans%10) ans = (ans+9)/10*10;
            ans += v[i];
        }
        ret = min(ret, ans);
    }while(next_permutation(v.begin(), v.end()));
    cout << ret << "\n";
    return 0;
}
