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
    int n, m = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        if(w > m) {
            k = m; m = w;
        }else if (w > k && w != m){
            k = w;
        }
    }
    cout << k << "\n";
    return 0;
}
