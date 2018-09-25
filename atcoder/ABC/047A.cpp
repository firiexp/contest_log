#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string x;
    if(a+b==c || b+c==a || c+a==b) x = "Yes";
    else x = "No";
    cout << x << "\n";
}