#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int d, g, ans = INF;
    cin >> d >> g;
    vector<int> p(d), c(d), solved(d, 0);
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }
    for (int i = 0; i < (1 << d); ++i) {
        int sum = 0;
        solved.assign(d, 0);
        for (int j = 0; j < d; ++j) {
            if (i & (1<<j)) {
                solved[j] = p[j];
                sum += p[j] * (j+1)*100 + c[j];
            }
        }
        for (int j = d-1; j >= 0 ; --j) {
            if(sum >= g) break;
            if(solved[j] != p[j]){
                int k = min(p[j]- solved[j], (g-sum + (j+1)*100 -1) / ((j+1)*100));
                solved[j] += k;
                sum += k * (j + 1) * 100;
            }
        }
        ans = min(accumulate(solved.begin(), solved.end(), 0), ans);
    }
    cout << ans << "\n";
    return 0;
}
