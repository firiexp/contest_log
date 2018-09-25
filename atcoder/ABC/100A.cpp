#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << ((max(a,b)>8) ? ":(\n" : "Yay!\n");
    return 0;
}
