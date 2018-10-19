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
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> v(n), s(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        v[i] = k;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        s[i+1] = sum;
    }
    for (int i = n-2; i >= 0; --i) {
        if(2*s[i+1] < v[i+1]){
            cout << n-i-1 << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}
