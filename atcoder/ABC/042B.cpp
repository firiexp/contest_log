#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    string k, ans;
    cin >> n >> l;

    vector<string> v = {};
    for (int i = 0; i < n; ++i) {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (const auto &a : v) {
        ans += a;
    }
    cout << ans;
}