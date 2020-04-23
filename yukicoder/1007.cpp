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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    k--;
    int cur1 = k, cur2 = k;
    ll ans1 = 0, ans2 = 0;
    while(cur1 > 0 && v[cur1-1] > 1) ans1 += v[--cur1];
    while(cur2+1 < n && v[cur2+1] > 1) ans2 += v[++cur2];
    if(cur1 > 0 && v[cur1-1] >= 1) ans1 += v[--cur1];
    if(cur2+1 < n && v[cur2+1] >= 1) ans2 += v[++cur2];
    if(v[k] == 0){
        puts("0");
    }else if(v[k] == 1){
        cout << max(ans1, ans2)+1 << "\n";
    }else {
        cout << ans1+ans2+v[k] << "\n";
    }
    return 0;
}