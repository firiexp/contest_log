#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n,k,x;
    cin >> n >> k;
    x = k;
    for (int i = 0; i < n - 1; ++i) {
        x *= k-1;
    }
    cout << x;
    return 0;
}