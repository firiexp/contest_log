#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n%k) cout << 1 << "\n";
    else cout << 0 << "\n";
    return 0;
}
