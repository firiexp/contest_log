#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int x, t;
    cin >> x >> t;
    cout << max(x-t, 0) << "\n";
    return 0;
}