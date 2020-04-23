#include <iostream>

#include <algorithm>
#include <array>

using ll = long long;
using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    int a[100];
    array<bool, 11000> dp{};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m += a[i];
    }
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 10000-a[i]; j >= 0; --j) {
            dp[j+a[i]] = dp[j]|dp[j+a[i]];
        }
    }
    cout << count(dp.begin(), dp.end(), true) << "\n";
    return 0;
}
