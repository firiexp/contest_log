#include <iostream>
using ll = long long;
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(a-c)<=d || (abs(a-b) <= d && abs(b-c)  <= d)) cout << "Yes";
    else cout << "No";
    return 0;
}