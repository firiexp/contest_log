#include <iostream>
#include <set>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x, a, ans = 0;
    cin >> n >> x;
    multiset<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.insert(a);
    }
    for (auto &k : v) {
        ans+=v.count(x-k);
    }
    cout << ans << "\n";
    return 0;
}
