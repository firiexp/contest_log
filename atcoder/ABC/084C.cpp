#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>

static const int INF = 1000000007;
using ll = long long;
using namespace std;

int main() {
    unsigned n;
    cin >> n;
    vector<int> cc(n), ss(n), ff(n);
    for (int i = 0; i < n-1; ++i) {
        cin >> cc[i] >> ss[i] >> ff[i];
    }
    for (int i = 0; i < n; ++i) {
        int t = 0;
        for (int j = i; j < n-1; ++j) {
            t = (t + ff[j] - 1) / ff[j] * ff[j];
            if(t < ss[j]) t = ss[j];
            t += cc[j];
        }
        cout << t << "\n";
    }
    return 0;
}
