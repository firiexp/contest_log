#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    u32 n;
    cin >> n;
    vector<int> v(n);
    for (auto &&a : v) cin >> a;
    sort(v.begin(), v.end());
    cout << v[n-1] - v[0] << "\n";
    return 0;
}
