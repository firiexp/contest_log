#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <random>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        m[k]++;
    }
    int x; cin >> x;
    for (int i = 0; i < x; ++i) {
        int k;
        scanf("%d", &k);
        m[k]--;
    }
    for (auto &&a : m) if(a.second<0) {cout << "NO\n"; return 0;}
    cout << "YES\n";
    return 0;
}
