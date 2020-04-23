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
    int n, x;
    vector<int> v;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    sort(v.begin(), v.end());
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if(sum < x) ans++;
        else {
            cout << (sum == x ? ans+1 : ans) << "\n";
            return 0;
        }
    }
    cout << (sum == x ? ans : ans-1) << "\n";
    return 0;
}
