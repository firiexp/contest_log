#include <iostream>
using ll = long long;
using namespace std;

/* initialize */

/* main */
int main() {
    int n,m;
    cin >> n >> m;
    if (n == 1) n = 14; if (m == 1) m = 14;
    if(n>m) cout << "Alice";
    else if (n==m) cout << "Draw";
    else if (n<m) cout << "Bob";
    return 0;
}