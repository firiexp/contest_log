#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int y = a*b/__gcd(a,b);
    cout << ((n+y-1)/y)*y << "\n";
    return 0;
}
