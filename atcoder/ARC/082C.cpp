#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    multiset<int> v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.insert(k);
    }
    int ans = 0;
    for (int i = 0; i < 100000; ++i) {
        ans = max(int(v.count(i-1) + v.count(i) + v.count(i+1)), ans);
    }
    cout << ans << "\n";
    return 0;
}
