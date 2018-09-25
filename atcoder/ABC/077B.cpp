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
    int n;
    cin >> n;
    if(n == 1) {cout << 1 << "\n"; return 0;}

    for (int i = 1; i <= n; ++i) {
        if(n < i*i) {cout << (ll)(i-1)*(i-1) << "\n"; return 0;}
    }
    return 0;
}
