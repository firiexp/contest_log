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
    int a, b, c, x;
    vector<int> v(1001, 0);
    cin >> a >> b >> c >> x;
    for (int i = 0; i <= c; ++i) {
        v[i]++;
    }
    for (int j = c; j >= 0; --j) {
        for (int i = 1; i <= b; ++i) {
            v[j+2*i] += v[j];
        }
    }
    for (int k = 2*b+c; k >= 0; --k) {
        for (int i = 1; i <= a; ++i) {
            v[k+10*i]+= v[k];
        }
    }
    cout << v[x/50] << "\n";
    return 0;
}
