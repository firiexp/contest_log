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
    int a, b;
    cin >> a >> b;
    if(a * b % 2) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}
