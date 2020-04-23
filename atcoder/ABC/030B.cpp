#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <cmath>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double q = 6.0*m;
    double p = 30.0*(n%12)+q/12;
    cout << setprecision(15) << min(fabs(p-q), 360-fabs(p-q)) << "\n";
    return 0;
}
