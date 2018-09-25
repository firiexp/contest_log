#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    n = n % 500;
    if (n > a) cout << "No";
    else cout << "Yes";
    return 0;
}