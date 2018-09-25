#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        string w = to_string(i);
        int k = 0;
        for (auto &c : w) {
            k += c - '0';
        }
        if (a <= k && k <= b){
            ans+=i;
        }
    }
    cout << ans << "\n";
    return 0;
}
