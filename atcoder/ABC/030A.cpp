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
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double T = b/a , A = d/c;
    if(T > A) cout << "TAKAHASHI\n";
    else if (T == A) cout << "DRAW\n";
    else if (T < A) cout << "AOKI\n";
    return 0;
}
