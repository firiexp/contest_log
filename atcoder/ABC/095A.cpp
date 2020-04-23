#include <iostream>
using ll = long long;
using namespace std;

int main() {
    char a;
    int ans = 700;
    for (int i = 0; i < 3; ++i) {
        cin >> a;
        if (a == 'o') ans += 100;
    }
    cout << ans;
    return 0;
}