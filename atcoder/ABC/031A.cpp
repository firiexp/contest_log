#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, d;
    cin >> a >> d;
    if(d < a) cout << a*(d+1) << "\n";
    else cout << (a+1)*d << "\n";
    return 0;
}
