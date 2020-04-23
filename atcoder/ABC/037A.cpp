#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << c/min(a,b) << "\n";
    return 0;
}
