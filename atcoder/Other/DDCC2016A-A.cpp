#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(20) << c * b / a << "\n";
    return 0;
}
