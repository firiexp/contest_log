#include <iostream>
using namespace std;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if (n < k) k = n;
    cout << x * k + y * (n - k) << "\n";
}

