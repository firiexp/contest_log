#include <iostream>
using ll = long long;
using namespace std;

/* initialize */

/* main */
int main() {
    int N;
    cin >> N;
    int u = 0, i = 0;
    for(;;i++) {
        if (i * (i + 1) > 2 * N){ u = i; break;}
    }
    int v = (u*(u+1))/2 - N;
    for (i= 1; i <= v-1; ++i) {
        cout << i << "\n";
    }
    for (i = v+1; i <= u; i++){
        cout << i << "\n";
    }
    return 0;
}