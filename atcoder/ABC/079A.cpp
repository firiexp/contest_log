#include <iostream>
using ll = long long;
using namespace std;

int main() {
    string a;
    cin >> a;
    for (int i = 0; i < 2; ++i) {
        if (a[i] != a[i+1] || a[i+1] != a[i+2]) continue;
        else cout << "Yes"; return 0;
    }
    cout << "No";
    return 0;
}