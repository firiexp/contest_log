#include <iostream>
#include <algorithm>
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
    int n, d;
    cin >> n >> d;
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &v[i][1], &v[i][2], &v[i][0]);
    }
    sort(v.begin(),v.end());
    int l = 0;
    multiset<int> Y, X;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        Y.emplace(v[i][1]);
        X.emplace(v[i][2]);
        while(v[i][0]-v[l][0] > d){
            Y.erase(Y.find(v[l][1]));
            X.erase(X.find(v[l][2]));
            l++;
        }
        ans = max(ans, (ll)(*X.crbegin() - *X.cbegin())*(*Y.crbegin() - *Y.cbegin()));
    }
    cout << ans << "\n";
    return 0;
}