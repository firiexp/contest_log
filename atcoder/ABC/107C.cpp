#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <list>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    unsigned n, k;
    cin >> n >> k;
    vector<int> v;
    int ans = INF, prv = -INF;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if(prv <= 0 && 0 <= a) {
            if(prv != 0) {
                v.emplace_back(0);
                d = i;
            }
        }
        v.emplace_back(a);
        prv = a;
    }

    for (int i = 0; i+k < n+1; ++i) {
        ans = min(ans, v[i+k]-v[i]+min(abs(v[i+k]), abs(v[i])));
    }
    cout << ans << "\n";
    return 0;
}
