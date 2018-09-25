#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b;
    char k;
    cin >> a >> k >> b;
    cout << (k == '+'? a + b : a - b);
    return 0;
}