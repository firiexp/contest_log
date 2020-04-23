#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a[3];
    for (auto &i : a) cin >> i;
    for (int j = 0; j < 2; ++j) {
        if (a[j].back() != a[j+1][0]) {
            cout << "NO"; return 0;
        }
    };
    cout << "YES";
    return 0;
}