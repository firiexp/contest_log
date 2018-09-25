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
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v.emplace_back(a-1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = v[i];
        if(v[k] == i && v[i] == k) ans++;
    }
    cout << ans/2 << "\n";
    return 0;
}
