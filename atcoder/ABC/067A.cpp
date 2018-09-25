#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a*b*(a+b)%3 == 0) cout << "Possible"; else cout << "Impossible";
    return 0;
}