#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <set>

static const int INF = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

int main() {
    int n;
    cin >> n;
    set<char> x;
    for (int i = 0; i < n; ++i) {
        char k;
        cin >> k;
        x.insert(k);
    }
    cout << (x.size() == 3 ? "Three" : "Four") << "\n";
    return 0;
}
