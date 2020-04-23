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
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> u;
    for (auto &&i : v) {
        scanf("%d", &i);
        if(i != -1) u.emplace_back(i);
    }
    if(*max_element(v.begin(),v.end()) == -1){
        puts("-1");
        return 0;
    }
    sort(u.begin(),u.end());
    ll ans = 0;
    for (int i = 0; i < u.size(); ++i) {
        ans = __gcd(ans, u[i]*u[i]);
    }
    cout << ans << "\n";
    return 0;
}