#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    if(abs(x-b)>abs(x-a)) cout << "A";
    else cout << "B";
    return 0;
}