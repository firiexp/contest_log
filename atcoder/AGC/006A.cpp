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
    int n, k;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i <= n; ++i) {
        if(s.substr(n-i, i) == t.substr(0, i)){
            k = i;
        }
    }
    cout << 2*n-k << "\n";
    return 0;
}
