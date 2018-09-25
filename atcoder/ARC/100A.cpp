#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 2 - 170;

int main() {
    int n;
    cin >> n;
    vector<ll> v;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a-i;
        v.emplace_back(a-i);
    }
    ll ans = 0, p, q, r;
    sort(v.begin(), v.end());
    if(n%2){
        p = v[n/2];
        q = v[n/2];
        r = v[n/2];
    }else {
        p = (v[n/2]+v[n/2-1])/2;
        q = (v[n/2]+v[n/2-1])/2+1;
        r = (v[n/2]+v[n/2-1])/2-1;
    }

    ll ans2 = 0, ans3 = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(v[i]-p);
    }
    for (int i = 0; i < n; ++i) {
        ans2 += abs(v[i]-q);
    }
    for (int i = 0; i < n; ++i) {
        ans3 += abs(v[i]-r);
    }
    cout << min({ans, ans2, ans3}) << "\n";
    return 0;
}
