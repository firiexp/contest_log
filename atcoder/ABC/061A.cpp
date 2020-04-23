#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a<=c && c<=b) cout << "Yes";
    else cout << "No";
    return 0;
}