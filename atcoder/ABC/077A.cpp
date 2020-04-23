#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    for (int i = 0; i < 3; ++i) {
        if (a[i] != b[2-i]) {cout << "NO\n"; return 0;}
    }
    cout << "YES\n";
    return 0;
}