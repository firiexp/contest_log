#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    if(x[0] == 'S' && y[0] == 'H') cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}
