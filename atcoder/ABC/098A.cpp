#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(a+b, max(a*b, a-b) );
    return 0;
}