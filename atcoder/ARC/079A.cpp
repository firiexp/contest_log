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
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a-1].insert(b-1);
        v[b-1].insert(a-1);
    }
    for (int i = 1; i < n-1; ++i) {
        if(v[0].count(i) && v[i].count(n-1)){
            cout << "POSSIBLE\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
