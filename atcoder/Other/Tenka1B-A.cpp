#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string s;
    int ans = 0;
    cin >> s;
    for (auto &&item : s) ans += item - '0';
    cout << ans << "\n";
    return 0;
}
