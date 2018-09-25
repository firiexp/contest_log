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
    int n, x = INF;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, p = 0;
        cin >> a;
        while(a % 2 == 0){
            a/=2;
            p++;
        }
        x = min(x, p);

    }
    cout << x << "\n";
    return 0;
}
