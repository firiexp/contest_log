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
    int n, a, b;
    cin >> n >> a >> b;
    cout << max(a+b-n, 0) << "\n";
    return 0;
}
