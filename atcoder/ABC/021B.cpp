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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    map<int, int> v;
    v[a]++; v[b]++;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    for (auto &&x : v) {
        if(x.second > 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}
