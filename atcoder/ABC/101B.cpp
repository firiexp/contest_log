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
    string n;
    cin >> n;
    int k = 0;
    for (auto &&a : n) {
        k += a-'0';
    }
    cout << (stoi(n)% k == 0 ? "Yes" : "No") << "\n";
    return 0;
}
