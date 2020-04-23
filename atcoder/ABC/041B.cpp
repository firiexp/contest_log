#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((ll)a * b)%INF * c % INF << "\n";
    return 0;
}
