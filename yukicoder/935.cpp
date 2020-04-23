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
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int n; string s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i);
    vector<ll> val(n+1, INF<ll>);
    val[0] = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        ll sum = 0;
        for (int j = i; j < n; ++j) {
            cnt += (s[j] == 'E');
            sum += v[j];
            val[cnt] = min(val[cnt], sum);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        scanf("%d", &x);
        cout << upper_bound(val.begin(),val.end(), x) - val.begin()-1 << "\n";
    }
    return 0;
}