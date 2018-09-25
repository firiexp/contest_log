#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    u32 n, k;
    cin >> n >> k;
    vector<int> v;
    v.reserve(k);
    for (int j = 0; j < k; ++j) {
        v.emplace_back(0);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.emplace_back(a);
    }
    sort(v.begin(), v.end(), greater<>());
    cout << accumulate(v.begin(), v.begin()+k, 0) << "\n";
    return 0;
}
