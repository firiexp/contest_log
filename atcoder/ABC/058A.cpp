#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a+c == 2*b) cout << "YES"; else cout << "NO";
    return 0;
}