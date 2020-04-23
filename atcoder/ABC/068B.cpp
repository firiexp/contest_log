#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, ans = 1;
    cin >> n;
    vector<int> A = {2, 4, 8, 16, 32, 64};
    for (auto &&a : A) {
        if(a <= n) ans=a;
    }
    cout << ans << "\n";
    return 0;
}
