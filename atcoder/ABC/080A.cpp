#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a*n, b) << "\n";
    return 0;
}