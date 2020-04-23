#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a+b, b+c),c+a) << "\n";
    return 0;
}