#include <iostream>
using ll = long long;
using namespace std;

/* initialize */

/* main */
int main() {
    char a, b;
    cin >> a >> b;
    auto f = [](char x){return (x=='H'?1:0);};
    int c = f(a)^f(b);
    if(c==0) cout << 'H'; else cout << 'D';
    return 0;
}