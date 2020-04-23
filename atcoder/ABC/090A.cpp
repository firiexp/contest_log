#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a[3];
    for (auto &i : a) cin >> i;
    for (int j = 0; j < 3; ++j) cout << a[j][j];
    cout << "\n";
    return 0;
}