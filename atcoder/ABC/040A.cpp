#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    cout << min(x-1, n-x) << "\n";
    return 0;
}
