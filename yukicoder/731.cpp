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
    int n;
    cin >> n;
    vector<double> vy, vx;

    for (int i = 0; i < n; ++i) {
        double k;
        cin >> k;
        vy.emplace_back(k);
        vx.emplace_back(double(i));
    }
    double xy = 0, x = 0, y = 0, x2 = 0;
    for (int i = 0; i < n; ++i) {
        xy += vx[i] * vy[i];
        x += vx[i];
        y += vy[i];
        x2 += vx[i] * vx[i];
    }

    double a = (xy * n - x * y) /(x2 * n - x*x);
    double b = (x2 * y - xy * x) / (x2 * n - x*x);
    double c = 0;
    for (int i = 0; i < n; ++i) {
        double k = b + a * i;
        c += pow(vy[i]-k, 2);
    }
    cout << setprecision(16) << b << " " << a << "\n";
    cout << c << "\n";
    return 0;
}
