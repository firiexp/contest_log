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
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.emplace_back(k);
    }
    auto x = minmax_element(v.begin(), v.end());
    cout << *x.second - *x.first << "\n";
    return 0;
}
