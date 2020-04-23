#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;
using P = pair<int, int>;
int main() {
    unsigned n;
    cin >> n;
    vector<int> v(n);
    vector<P> v2;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v2.emplace_back(upper_bound(v.begin(), v.end(), v[i]+b)-1,
                        lower_bound(v.begin(), v.end(), v[i]-a));
    }
    sort(v2.begin(), v2.end());

    return 0;
}
