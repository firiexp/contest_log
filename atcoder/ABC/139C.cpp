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
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    v.emplace_back(INF<int>);
    int cur = 0, curr = 0, ans = 0;
    while(cur < n){
        if(v[cur] >= v[cur+1]) cur++, curr++;
        else {
            ans = max(ans, curr);
            curr = 0;
            cur++;
        }
    }
    cout << ans << "\n";
    return 0;
}