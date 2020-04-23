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
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> v;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        v[x]++;
    }
    GPQ<int> v2;
    for (auto &&x : v) if(x.second) v2.emplace(x.second);
    int ans = 0;
    int p = (int)v2.size()-k;
    for (int i = 0; i < p; ++i) {
        ans += v2.top(); v2.pop();
    }
    cout << ans << "\n";
    return 0;
}
