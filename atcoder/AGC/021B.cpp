#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    for (int i = 0; i < n; ++i) {
        vector<long double> arg;
        int x1, y1;
        tie(x1, y1) = v[i];
        for (int j = 0; j < n; ++j) {
            if(i != j){
                int x2, y2;
                tie(x2, y2) = v[j];
                arg.emplace_back(atan2(y2-y1, x2-x1));
            }
        }
        sort(arg.begin(), arg.end());
        long double maxt = 2*acos(-1)-arg[n-2]+arg[0];
        for (int j = 0; j < n-2; ++j) {
            maxt = max(maxt, arg[j+1]-arg[j]);
        }
        cout << setprecision(20) << max((maxt-acos(-1))/(2*acos(-1)), 0.0L) << "\n";
    }
    return 0;
}
