#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    unsigned n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int a = 1;
        for (int j = i+1; j < n; ++j) {
            if(v[j-1]*2 >= v[j]) a++;
            else break;
        }
        i += max(a-1, 0);
        ans = max(ans, a);
    }
    cout << ans << "\n";
    return 0;
}
