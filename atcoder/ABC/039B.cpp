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
    int x;
    cin >> x;
    for (int i = 1; i <= pow(x, 0.25)+1; ++i) {
        int j = i * i * i * i;
        if(x == j) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
