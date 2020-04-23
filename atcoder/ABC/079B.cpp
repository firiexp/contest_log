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
    vector<ll> v;
    v.emplace_back(2);
    v.emplace_back(1);
    for (int i = 0; i < n; ++i) {
        v.emplace_back(v[i+1] + v[i]);
    }
    cout << v[n] << "\n";
    return 0;
}
