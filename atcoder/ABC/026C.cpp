#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> buka(n);
    vector<int> p(n);
    for (int i = 1; i <= n-1; ++i) {
        int k;
        cin >> k;
        buka[k-1].emplace_back(i);
    }
    for (int i = n-1; i >= 0; --i) {
        if(buka[i].empty()) p[i] = 1;
        else {
            int mi = INF<int>, ma = 0;
            for (auto &&j : buka[i]) {
                mi = min(mi, p[j]);
                ma = max(ma, p[j]);
            }
            p[i] = 1 + mi + ma;
        }

    }
    cout << p[0] << "\n";
    return 0;
}
