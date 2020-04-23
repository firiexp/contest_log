#include <iostream>
#include <vector>

static const int INF = 1000000007;
using ll = long long;
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> dp(30000, INF), v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.emplace_back(a);
    }
    for (auto &a : v) {
        *lower_bound(dp.begin(), dp.end(), a) = a;
    }
    cout << n-(lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << "\n";
    return 0;
}
